#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char titles[101][101];
	char filename[30];
	char buf[20];
	char search[20];
	int i;
	//making array of filenames
	for (i = 0; i <= 100; i++) {
		if (i < 10) sprintf(titles[i], "00%d.txt", i);
		else if (i >= 10 && i < 100) sprintf(titles[i], "0%d.txt", i);
		else if (i == 100) sprintf(titles[i], "%d.txt", i);
	}

	FILE *input = fopen("search.txt", "r");
	fscanf(input, "%s", search);
	fclose(input);

	//search in files
	for (i = 0; i <= 100; i++) {
		strcpy(filename, "chewy_files/");
		strcat(filename, titles[i]);	
		FILE *report = fopen(filename, "r");
		fscanf(report, "%s", buf);
		if (strcmp(search, buf) == 0) printf("%s is in %s\n", search, filename);
		fclose(report);
	}
	return 0;
}
