#include <signal.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // typedef int pid_t
    pid_t dpid = getpid();

    int res = kill (dpid, SIGKILL);
    return 0;
}