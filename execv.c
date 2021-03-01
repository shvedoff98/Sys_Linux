#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>



int main(void)
{
	pid_t result, childpid;
	char *args[] = {"Hello","world", NULL};
	int exit_status;
	printf("PID of parent = %d\n", getpid());
	result = fork();
	if (result == -1)
	{
		fprintf (stderr, "Fork error\n");
		return 1;
	}
	
	
	for(int i = 0; i < 20; i++)
	{
		if (result == 0)
		{
			
			printf("PID of cp_sys = %d\n", getpid());
			execv ("./cp1_sys", args);
			fprintf(stderr, "Exec error\n");
			return 1;
		}
	}
	childpid = wait (&exit_status);
	if (WIFEXITED (exit_status))
	{
		printf ("Process with PID = %d\n", childpid, WEXITSTATUS (exit_status));
	}




	return 0;
	
}
