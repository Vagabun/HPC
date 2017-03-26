#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main () {
	srand(time(NULL));
	int num = rand() % (100 + 1 - 0) + 0;
	double num_2 = ((double)rand())/RAND_MAX;
	printf("%d\n", num);
	printf("%.12lf\n", num_2);
	return 0;
}
