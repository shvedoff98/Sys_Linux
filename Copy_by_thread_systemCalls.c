#include <stdio.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 4096


struct thread_arg
{
    	char* file, *file2;
};

void * cp_sys (void * arg)
{
    	char buffer[BUF_SIZE];  
    	struct thread_arg targ = *(struct thread_arg *) arg;

   	int in,out;
    	ssize_t bytes;

    

   	in = open( targ.file, O_RDONLY | O_CREAT );
    	if (in == -1)
    	{
        	fprintf(stderr,"Cannot open file %s\n", targ.file);
        	return NULL;
    	}

    	out = open( targ.file2, O_WRONLY | O_CREAT | O_TRUNC, 0640);
    	if ( out == -1 )
    	{
        	fprintf(stderr, "Cannot creat file %s\n", targ.file2);
        	return NULL;
    	}

    	while ((bytes = read ( in, buffer, BUF_SIZE)) > 0)
        	write (out , buffer, bytes );

    	close (in);
    	close (out);
    	return NULL;
}

int main (void)
{
    	pthread_t thread;
    	int result;
    	struct thread_arg targ;
    	targ.file = "file.in";
    	targ.file2 = "file.out";


    	result = pthread_create(&thread, NULL, &cp_sys, &targ);

    
    	if (pthread_join (thread, NULL) != 0)
	{
		fprintf (stderr, "Join error\n");
		return 1;
	}
	

	
    	return 0;
}
