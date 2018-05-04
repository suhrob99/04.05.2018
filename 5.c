/*Выводит колонки от m до n из файла*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int ch;
	int m, n;
	int i = 1;
	FILE *pf;

	if(argc != 2)
	{
		fprintf(stderr, "enter the: %s file_for_reading_name\n", argv[0]); // example_(1/2/big).txt
		exit(EXIT_FAILURE);
	}

	if((pf = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "open error %s", argv[1]);
		exit(EXIT_FAILURE);
	}

	printf("enter the m and n: ");
	scanf("%i %i", &m, &n);
	printf("\n");

	while(1)
	{
			ch = getc(pf);
			if(i >= m && i <= n)
				putc(ch, stdout);
			if(ch == '\n')
			{
				putc(ch, stdout);
				i = 0;
			}
			if(ch == EOF)
				exit(EXIT_SUCCESS);
			++i;
	}

	return 0;
}