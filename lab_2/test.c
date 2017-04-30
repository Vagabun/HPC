#include <stdio.h>
#include <stdlib.h>

int main () {
	int **array = malloc(2 * sizeof(int*));
	int i;
	for (i = 0; i < 2; i++) array[i] = malloc(1000000 * sizeof(int));

	array[0][999999] = 54;
	printf("%d\n", array[0][999999]);
	free(array);
	return 0;
}
