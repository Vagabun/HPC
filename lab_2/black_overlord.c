#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000

int main () {

	double  S, a, b, c, sum, step, y1, y2, y3, y4;
	int i;
	FILE *input;
	input = fopen("input.txt", "r");
	fscanf(input, "%lf %lf %lf %lf", &S, &a, &b, &c);

	if (a > b) {
		i = a;
		a = b;
		b = i;
	}

	step = (b - a) / N;
	sum = 0.0;	
	y1 = 0.0;
	y2 = 0.0;
	y3 = 0.0;
	y4 = 0.0;
	if (c == 0) {
		for (i = 0; i < N; i++) {
			 y1 += sin(a + (i + 0.5) * step) * step;
			 y2 += (a + (i + 0.5) * step) * step * cos(a + (i + 0.5) * step) * step;
		}
	}	
	printf("%lf\n", y2);

	return 0;
}
