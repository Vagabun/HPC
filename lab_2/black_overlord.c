#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {

	int S, a, b, c;

	FILE *input;
	input = fopen("input.txt", "r");
	fscanf(input, "%d %d %d %d", &S, &a, &b, &c);
	printf("%d %d %d %d\n", S, a, b, c);

	return 0;
}
