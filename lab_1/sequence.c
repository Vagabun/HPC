#include <stdio.h>
#include <stdlib.h>

#define N 20

int F[N] = {0, 1};
int main() {
	int i;
	for (i = 2; i <= N; i++) F[i] = F[i-1] + F[i-2];
	for (i = 0; i <= N; i++) printf("%d ", F[i]);
	printf("\n");
	
	return 0;
}
