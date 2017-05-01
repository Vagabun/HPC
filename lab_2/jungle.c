#include <stdio.h>
#include <stdlib.h>

int min (int a, int b) {
	if (a < b) return a;
	else return b;
}

int find_ind (int a, int b, int first_index, int second_index) {
	if (a < b) return first_index;
	else return second_index;
}

int main() {
	
	const int maxSize = 1000;
	int **game = malloc(maxSize * sizeof(int*));
	int **path = malloc(maxSize * sizeof(int*));
	int **route = malloc(2 * sizeof(int*));
	int i, j, size_i, size_j;
	for (i = 0; i < maxSize; i++) { 
		game[i] = malloc(maxSize * sizeof(int));
		path[i] = malloc(maxSize * sizeof(int));
	}
	for (i = 0; i < 2; i++) 
		route[i] = malloc(1000000 * sizeof(int));
	FILE *input;
	FILE *output;
	input = fopen("jungle_game.txt", "r");
	fscanf(input, "%d %d", &size_i, &size_j);
	for (i = 1; i <= size_i; i++) 
		for (j = 1; j <= size_j; j++) 
			fscanf(input, "%d", &game[i][j]);
	for (i = 1; i <= size_i; i++) {
		for (j = 1; j <= size_j; j++) {
		       path[i][j] = min(path[i-1][j], path[i][j-1]) + game[i][j];
		       if (i == 1 && j == 1) {
			       route[0][size_j*i+j-size_j] = i;
			       route[1][size_j*i+j-size_j] = j;
		       }

		       if (i == 1 && j != 1) {
			       route[0][size_j*i+j-size_j] = i;
			       route[1][size_j*i+j-size_j] = j - 1;
		       }
		       if (j == 1 && i != 1) {
			       route[0][size_j*i+j-size_j] = i - 1;
			       route[1][size_j*i+j-size_j] = j;
		       }
		       if (i != 1 && j != 1) {
			       route[0][size_j*i+j-size_j] = find_ind(path[i-1][j], path[i][j-1], i-1, i); 
			       route[1][size_j*i+j-size_j] = find_ind(path[i-1][j], path[i][j-1], j, j-1);
		       }

			        

		       //printf("%d ", path[i][j]);
		}
		//printf("\n");
	}		
	
	
	for (i = 0; i < 2; i++) {
		for (j = 1; j <= size_i*size_j; j++) 
			printf("%d ", route[i][j]);
		printf("\n");
	}
	printf("\n");
	j = size_i*size_j;
	while (1) {
		printf("[%d][%d] ", route[0][j], route[1][j]);
		if (route[0][j] == 1 && route[1][j] == 1) break;
		j = size_j * route[0][j] + route[1][j] - size_j;
	}	
	//route[0][999999] = 7;
	//route[999999][1] = 9;
	//printf("%d\n", route[0][999999]);
	
	
	
	
	/*for (i = 1; i <= size_i; i++) { 
		for (j = 1; j <= size_j; j++)
		       printf("%d ", game[i][j]);	
		printf("\n");
	}
	printf("\n");
	for (i = 1; i <= size_i; i++) { 
		for (j = 1; j <= size_j; j++)
		       printf("%d ", path[i][j]);	
		printf("\n");
	}*/
	free(game);
	free(path);
	free(route);
	return 0;
}
