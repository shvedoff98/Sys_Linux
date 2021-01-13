#include <stdio.h>
#include <stdlib.h>
int main(int argc, char ** argv)
{
	int c;
	FILE *in, *out;
	
	in = fopen(argv[1],"r");
	
	out = fopen(argv[2],"w");
	
	while((c = fgetc(in)) != EOF)
	{
		fputc(c,out);
	}
	exit(0);
}
