#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	const int maxSize = 100;
	int i, k, j, flag, r_counter, h_counter;
	char **harry = malloc(maxSize * sizeof(char*));
	char **ron = malloc(maxSize * sizeof(char*));
	char *buf = malloc(maxSize * sizeof(char));
	for (i = 0; i < 100; i++) {
		harry[i] = malloc(maxSize * sizeof(char));
		ron[i] = malloc(maxSize * sizeof(char));
	}
	
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
		if (flag) {
			i--;
			flag = 0;
		}
	}
	fprintf(output, "Harry's book of adventures:\n");
	for (i = 0; i <= h_counter; i++) fprintf(output, "%s", harry[i]);
	fprintf(output, "\nRon's book of adventures:\n");
        for (k = 0; k <= r_counter; k++) fprintf(output, "%s", ron[k]);	
	fclose(input);
	fclose(output);
	free(harry);
	free(ron);

	return 0;
}
