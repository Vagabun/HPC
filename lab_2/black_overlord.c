#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000
double f1 (double x) {
	return sin(x);
}

double f2 (double x) {
	return x*cos(x);
}

double f3 (double x) {
	return pow(x,2) + x - tan(x);
}

double f4 (double x) {
	return exp(x) + 3;
}

double integral(double(*f)(double x), double a, double b, int n) {
	double step = (b - a)/n;
	double area = 0.0;
	for (int i = 0; i < n; i++) {
		area += f(a + (i + 0.5) * step) * step;
	}
	return area;
}

int main () {

	double  x, S, a, b, c, sum, step, y1, y2, y3, y4;
	int i;
	FILE *input;
	input = fopen("input.txt", "r");
	fscanf(input, "%lf %lf %lf %lf", &S, &a, &b, &c);

	if (a > b) {
		i = a;
		a = b;
		b = i;
	}

	y1 = integral(f1, a, b, N);
	y2 = integral(f2, a, b, N);
	y3 = integral(f3, a, b, N);
	y4 = integral(f4, a, b, N);

	printf("%lf %lf %lf %lf\n", y1, y2, y3, y4);
	return 0;
}
