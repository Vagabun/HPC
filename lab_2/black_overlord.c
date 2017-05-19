#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000
const double eps = 10E-8;
double y[3];
double max_arr[3];

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
	for (int i = 0; i < n; i++) area += f(a + (i + 0.5) * step) * step;

	while (1) {
		double area_2 = 0.0;
		n *= 2;
		step = (b - a)/n;
		for (int i = 0; i < n; i++) area_2 += f(a + (i + 0.5) * step) * step;	
		if (fabs(area_2 - area) > eps && fabs(area_2 - area) < 1) {
			area = area_2;
		}
		else break;
	}

	return area;
}

int main () {

	double  S, a, b, c, rectangle, max;
	int i;
	FILE *input;
	FILE *output;
	input = fopen("lord_in.txt", "r");
	output = fopen("lord_out.txt", "w");
	fscanf(input, "%lf %lf %lf %lf", &S, &a, &b, &c);

	if (a > b) {
		i = a;
		a = b;
		b = i;
	}
	
	y[0] = integral(f1, a, b, N);
	y[1] = integral(f2, a, b, N);
	y[2] = integral(f3, a, b, N);
	y[3] = integral(f4, a, b, N);

	if (c != 0) rectangle = fabs((b - a) * c);
	
	if (c > 0) for (i = 0; i <= 3; i++) y[i] = y[i] - rectangle;
	else if (c < 0) for (i = 0; i <= 3; i++) y[i] = y[i] + rectangle;

	max = 0;
	for (i = 0; i <= 3; i++) if (y[i] <= S) max_arr[i] = y[i];
	for (i = 0; i <= 3; i++) if (max_arr[i] > max) max = max_arr[i];

	if (max == 0) fprintf(output, "Black Lord was deeply dissapointed by his servants\n");
	else fprintf(output, "Maximum available area for a glass is %lf\n", max);
	fprintf(output, "All possible areas: \n");
	for (i = 0; i <= 3; i++) fprintf(output, "%lf\n", y[i]);

	return 0;
}
