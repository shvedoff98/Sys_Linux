#include <stdio.h>

int main(int argc, char ** argv)
{	
	FILE *fp;
	int c;

	if (argc < 2)
	{
		fprintf(stderr,"Too few arguments \n");
	}
	fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		fprintf(stderr,"Cannot open file %s\n",argv[1]);
		return 1;
	}
	
	while ((c = fgetc(fp)) != EOF)
	{
		printf("%c",c);
	}
	
	fclose(fp);
	return 0;
}	
