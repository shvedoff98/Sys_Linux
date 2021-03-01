#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(void)
{
	for(int i = 0; i < 20; i ++)
	{
		printf("PID is %d\n", getpid());
		system ("./cp1_sys");
	
		return 0;
	}
}
