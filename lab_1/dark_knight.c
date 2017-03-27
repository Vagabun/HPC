#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main () {
	const int maxSize = 10;
	int *jam = malloc (maxSize * sizeof(int));
	int *praxis = malloc (maxSize * sizeof(int));
	int karlsson = 60;
	int counter_1 = 0;
	int counter_2 = 0;

	srand(time(NULL));
	int i;
	for (i = 0; i < maxSize; i++) {
		jam[i] = rand() % 21;
		praxis[i] = rand() % 21;
	}
	while (1) {
		if (rand() % 2) {
			if (counter_1 < maxSize) {
				karlsson -= praxis[counter_1];
				counter_1++;
			}
		}
		else {
			if (counter_2 < maxSize) {
				karlsson += jam[counter_2];
				counter_2++;
			}
		}
		if (karlsson <= 20) {
		       printf("%d kg - patient is diognosed with death from dystrophy\n", karlsson);
		       break;
		}
	        else if	(karlsson >= 100) {
			printf("%d kg - patient is diognosed with obesity, now any flights are impossible\n", karlsson);

			break;
		}
		else if (counter_1 == maxSize && counter_2 == maxSize) {
			printf("%d kg - patient is healthy\n", karlsson);
			break;
		}
	}
	free(jam);
	free(praxis);
	return 0;
}
