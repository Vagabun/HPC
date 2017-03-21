#include <stdio.h>
#include <stdlib.h>

int main () {
	char c, space, new_line;

	space = ' ';
	new_line = '\n';

	for (c = 'a'; c <= 'z'; c++)
		printf("%c - %d\n", c, (int)c);
	printf("space - %d\n", (int)space);
	printf("symbol of new line - %d\n", (int)new_line);
	return 0;
}
