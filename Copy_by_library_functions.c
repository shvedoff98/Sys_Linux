#include <stdio.h>
#include <stdlib.h>

int main (int argc, char ** argv)
{
	FILE *in, *out;
	int c;
	
//ERROR CHECKING
	if (argc < 3)
	{
		(stderr, "Too few arguments %s\n");
		return 1;
	}
	
	in = fopen(argv[1], "r");
	out = fopen(argv[2], "w");

	while ((c = fgetc(in)) != EOF;)
	{
		fputc(c,out);
	}

	
	exit(0);
}
	
