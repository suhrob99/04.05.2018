/*Объединяет соответствующие строки из разных файлов*/              //Вставляет пробелы в выводе
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE *pf_1, *pf_2;
	int ch_1, ch_2;

	if(argc != 3)
	{
		fprintf(stderr, "enter the: %s file_one_name file_two_name \n", argv[0]); // example_1.txt example_2.txt
		exit(EXIT_FAILURE);
	}

	if((pf_1 = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "open error %s", argv[1]);
		exit(EXIT_FAILURE);
	}

	if((pf_2 = fopen(argv[2], "r")) == NULL)
	{
		fprintf(stderr, "open error %s", argv[2]);
		exit(EXIT_FAILURE);
	}

	while(1)
	{
		while((ch_1 = getc(pf_1)) != '\n')
		{
			putc(ch_1, stdout);
			if(ch_1 == EOF)
				break;
		}
		while((ch_2 = getc(pf_2)) != '\n')
		{
			putc(ch_2, stdout);
			if(ch_2 == EOF)
				exit(EXIT_SUCCESS);
		}
		printf("\n");
	}

	if((fclose(pf_1)) != 0)
		fprintf(stderr, "close error %s\n", argv[1]);

	if((fclose(pf_2)) != 0)
		fprintf(stderr, "close error %s\n", argv[2]);

	return 0;
}