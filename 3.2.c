#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>



int main(void)
{
	pid_t result;
	char *args[] = {"Hello","blyat", NULL};
	
	result = fork();
	if (result == -1)
	{
		fprintf (stderr, "Fork error\n");
		return 1;
	}
	
	printf("PID of parent is %d\n", getpid());
	
	if (result == 0)
	{
		printf("PID of cp_sys = %d\n", getpid());
		execv ("./cp1_sys", args);
		fprintf(stderr, "Exec error\n");
		return 1;
	}



	return 0;
	
}
