#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main () {
	const int maxSize = 10;
	int *jam = malloc (maxSize * sizeof(int));
	int *praxis = malloc (maxSize * sizeof(int));
	int karlsson = 60;
	srand(time(NULL));
	//jam = (*int) malloc(maxSize * sizeof(int));
	int i;
	for (i = 0; i < maxSize; i++) {
		jam[i] = rand() % 21;
		praxis[i] = rand() % 11;
	}
	while (1) {
		if (rand() % 2) {
		}
	}
	/*for (i = 0; i < maxSize; i++) {
		printf("%d ", jam[i]);
	}
	printf("\n");
	for (i = 0; i < maxSize; i++) {
		printf("%d ", praxis[i]);
	}*/
	printf("%d\n", rand() % 2);
	free(jam);
	free(praxis);
	return 0;
}
