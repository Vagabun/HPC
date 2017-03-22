#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main () {
	srand(time(NULL));
	int num = rand() % (100 + 1 - 0) + 0;
	printf("%d\n", num);
	return 0;
}
