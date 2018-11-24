#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define FEED_OR_DIE_TAG 0
#define MILK_PRODUCING_TAG 1

void filename_maker(int rank, int sizeof_filename, char *filename) {
    snprintf(filename, sizeof_filename, "log_%d.txt", rank);
}

void cow_work(int rank) {
    int message;
    int milk;
    char filename[15] = "";
    MPI_Status status;
    
    filename_maker(rank, 15, filename);
    FILE *output = fopen(filename, "a");
    srand(time(NULL));

    while (1) {
        MPI_Ssend(0, 0, MPI_INT, 0, FEED_OR_DIE_TAG, MPI_COMM_WORLD);
        MPI_Recv(&message, 1, MPI_INT, 0, FEED_OR_DIE_TAG, MPI_COMM_WORLD, &status);
        if (message > 0) {
            fprintf(output, "Cow got %d units of hay\n", message);
            milk = message / 2;
            fprintf(output, "Cow produced %d units of milk\n", milk);
            MPI_Ssend(&milk, 1, MPI_INT, 0, MILK_PRODUCING_TAG, MPI_COMM_WORLD);
            usleep((rand() % 1000000 + 1)); //usleep(microseconds), 1000000 + 1 - between 1 and 1000000
        }
        else {
            fprintf(output, "Cow died\n");
            break;
        }
    }
    fclose(output);
}

void farmer_work(int size, int *milk) {
    int init_cow_counter = size - 1; //size = MPI_Comm_size, 1 master process
    int cow_counter = init_cow_counter;
    int hay = 100;
    int message;
    int fake_message; //for receiving hungry signal from cow
    int dead = -1;
    int get_milk;
    int cows[init_cow_counter];
    int i;
    int id_of_cow;
    char status_of_cow[10] = "";
    MPI_Status status;
    
    for (i = 0; i < init_cow_counter; ++i) {
        cows[i] = 1;
    }
    srand(time(NULL));

    while (1) {
        MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status); //peek into any message, but do not receive it
        id_of_cow = status.MPI_SOURCE;
        if (status.MPI_TAG == FEED_OR_DIE_TAG) {
            id_of_cow = status.MPI_SOURCE;
            MPI_Recv(&fake_message, 1, MPI_INT, id_of_cow, FEED_OR_DIE_TAG, MPI_COMM_WORLD, &status);
            if (hay > 0) {
                message = rand() % 10 + 1; //between 1 and 10
                if (hay - message < 0)
                    message = hay;
                hay -= message;
                MPI_Ssend(&message, 1, MPI_INT, id_of_cow, FEED_OR_DIE_TAG, MPI_COMM_WORLD); // (buffer, count of buffer, datatype, dest, msgtag, comm)
                printf("Farmer sent %d units of hay to cow number %d\n", message, id_of_cow);
                printf("Amount of hay left: %d\n", hay);
            }
            else {
                MPI_Ssend(&dead, 1, MPI_INT, id_of_cow, FEED_OR_DIE_TAG, MPI_COMM_WORLD);
                --cow_counter;
                cows[id_of_cow - 1] = 0;
                printf("Cow number %d was told to die\n", id_of_cow);
                printf("Cows status: ");
                for (i = 0; i < init_cow_counter; ++i) {
                   if (cows[i])
                        strcpy(status_of_cow, "alive");
                   else
                        strcpy(status_of_cow, "dead");
                    printf("%d - %s", i + 1, status_of_cow);
                    if (i == init_cow_counter - 1)
                        printf(";");
                    else
                        printf(", ");
                }
                printf("\n");
            }
        }
        else if (status.MPI_TAG == MILK_PRODUCING_TAG) {
            MPI_Recv(&get_milk, 1, MPI_INT, MPI_ANY_SOURCE, MILK_PRODUCING_TAG, MPI_COMM_WORLD, &status);
            *milk += get_milk;
            printf("Farmer got %d units of milk from cow %d\n", get_milk, id_of_cow);
        }
        if (cow_counter <= 0)
            break;
    }
}

int main(int argc, char *argv[]) {
    int rank;
    int size;
    int milk = 0;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0)
        farmer_work(size, &milk);
    else
        cow_work(rank);
    if (rank == 0)
        printf("Total amount of milk produced: %d units\n", milk);
    MPI_Finalize();
    
    return 0;
}
