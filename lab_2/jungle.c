#include <stdio.h>
#include <stdlib.h>

int min (int a, int b) {
	if (a < b) return a;
	else return b;
}

int main() {
	
	const int maxSize = 1000;
	int **game = malloc(maxSize * sizeof(int*));
	int **path = malloc(maxSize * sizeof(int*));
	int i, j, size_i, size_j;
	for (i = 0; i < maxSize; i++) { 
		game[i] = malloc(maxSize * sizeof(int));
		path[i] = malloc(maxSize * sizeof(int));
	}
	FILE *input;
	FILE *output;
	printf("%d\n", path[0][5]);
	input = fopen("jungle_game.txt", "r");
	fscanf(input, "%d %d", &size_i, &size_j);
	for (i = 1; i <= size_i; i++) 
		for (j = 1; j <= size_j; j++) 
			fscanf(input, "%d", &game[i][j]);
	for (i = 1; i <= size_i; i++) {
		for (j = 1; j <= size_j; j++) {
		       path[i][j] = min(path[i-1][j], path[i][j-1]) + game[i][j];
		       printf("%d ", path[i][j]);
		}
		printf("\n");
	}		
	
	
	printf("%d\n", min(15, 15));	
	
	
	
	
	/*for (i = 0; i < size_i; i++) { 
		for (j = 0; j < size_j; j++)
		       printf("%d ", game[i][j]);	
		printf("\n");
	}
	printf("\n");
	for (i = 1; i <= size_i; i++) { 
		for (j = 1; j <= size_j; j++)
		       printf("%d ", path[i][j]);	
		printf("\n");
	}*/
	return 0;
}
