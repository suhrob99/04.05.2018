/*Копирование файла с заменой строчных букв заглавными*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int ch;
	FILE *pfr, *pfw;

	if(argc != 3)
	{
		fprintf(stderr, "enter the: %s file_for_reading_name file_for_writing_name \n", argv[0]); // example_1.txt
		exit(EXIT_FAILURE);
	}

	if((pfr = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "open error %s", argv[1]);
		exit(EXIT_FAILURE);
	}

	if((pfw = fopen(argv[2], "w")) == NULL)
	{
		fprintf(stderr, "open error %s", argv[2]);
		exit(EXIT_FAILURE);
	}

	while((ch = getc(pfr)) != EOF)
	{
		if(ch > 90)
			ch -= 32;
		putc(ch, pfw);
	}

	if((fclose(pfr)) != 0)
		fprintf(stderr, "close error %s\n", argv[1]);

	if((fclose(pfw)) != 0)
		fprintf(stderr, "close error %s\n", argv[2]);

	return 0;
}