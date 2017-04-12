#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	char harry[100][100];
	char ron[100][100];
	char buf[100];
	int i, k, j, flag, r_counter, h_counter;
	FILE *input;
	FILE *output;

	input = fopen("input.txt", "r");
	output = fopen("output.txt", "w");

	h_counter = 0, r_counter = 0;
	while (fgets(buf, 100, input) != NULL) {
		if (strcmp(buf, "\n") == 0) break;
		strcpy(harry[h_counter], buf);
		h_counter++;
	}
	while (fgets(buf, 100, input) != NULL) {
		strcpy(ron[r_counter], buf);
		r_counter++;
	}
	h_counter--;
	r_counter--;
	flag = 0;
	for (i = 0; i <= h_counter; i++) {
		for (k = 0; k <= r_counter; k++) {
			if (strcmp(harry[i], ron[k]) == 0) {
				if (h_counter >= r_counter) {
					for (j = i; j <= h_counter; j++) {
						strcpy(harry[j], harry[j+1]);
					}
					h_counter--;
					flag = 1;
					//i--;
				}
				else if (h_counter < r_counter) {
					for (j = k; j <= r_counter; j++) {
						strcpy(ron[j], ron[j+1]);
					}
					r_counter--;
					k--;
				}
			}
		}
		printf("%d\n", i);
	}
	printf("%d %d\n", h_counter, r_counter);
	//for (k = 0; k < i; k++) fprintf(output, "%s", harry[i]);
	for (i = 0; i <= h_counter; i++) printf("%s", harry[i]);
        for (k = 0; k <= r_counter; k++) printf("%s", ron[k]);
	//printf("%s", ron[r_counter-1]);
	//for (i = 0; i < 2; i++) printf("%s", ron[i]);
	/*for (i = 0; i <= 2; i++) {
		fgets(str[i], 100, input);
	}
	for (i = 0; i <= 2; i++) {
		fprintf(output, "%s", str[i]);
	}*/

}
