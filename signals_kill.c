#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // typedef int pid_t
    pid_t dpid;
    if (argc < 2)
    {
        fprintf (stderr, "Too few arguments\n");
        return 1;
    }
    dpid = atoi (argv[1]);

    int res = kill (dpid, SIGKILL);
    if ( res == -1 )
    {
        fprintf(stderr, "Cannot send signal\n");
        return 1;
    }
    
    if (res == 0)
    {
        fprintf(stdout, "Succesfully completed.\n");
        return 0;
    }
    return 0;
}