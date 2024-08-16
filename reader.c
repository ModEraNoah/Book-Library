#include<stdio.h>

char * readFile()
{
	FILE* file;
	file = fopen("./input-testfile.txt", "r");

	if (!file)
		printf(">>>>>>>> Error");

	printf("printing file: ");
	int cur;
	while ((cur = fgetc(file)) != EOF)
	{
		printf("%c", cur);
		// putchar(cur);
	}

	fclose(file);
}
