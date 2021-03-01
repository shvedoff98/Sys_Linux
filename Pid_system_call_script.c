#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(void)
{
        printf("PID is %d\n", getpid());
        system ("./cp1_sys");

        return 0;
}

