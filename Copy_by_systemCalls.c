#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 4096

char buffer[BUF_SIZE];

int main(int argc, char ** argv)
{
	int in,out;
	ssize_t bytes;

	if (argc < 3)
	{
		fprintf(stderr,"Too few arguments\n");
		return 1;
	}

	in = open( argv[1], O_RDONLY | O_CREAT );
	if (in == -1)
	{
		fprintf(stderr,"Cannot open file %s\n", argv[1]);
		return 1;
	}

	out = open( argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0640);
	if ( out == -1 )
	{
		fprintf(stderr, "Cannot creat file %s\n", argv[2]);
		return 1;
	}

	while ((bytes = read ( in, buffer, BUF_SIZE)) > 0)
		write (out , buffer, bytes );

	close (in);
	close (out);
	return 0;
}
