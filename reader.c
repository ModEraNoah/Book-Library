#include<stdio.h>
#include <stdlib.h>

char * readFile()
{
	FILE* file;
	file = fopen("./input-testfile.txt", "r");

	if (!file)
		printf(">>>>>>>> Error");

	printf("printing file: ");
	char *res = malloc(sizeof(char) * 31);
	int cur;
	int i = 0;
	while ((cur = fgetc(file)) != EOF)
	{
		// printf("length of char*: %d\n", i);
		printf("%c", cur);
		*(res + i) = cur;
		i++;
		// putchar(cur);
	}
	*(res+i) = '\0';

	fclose(file);

	return res;
}
