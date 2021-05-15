#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <sys/un.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    struct sockaddr_un addr;

    if (argc < 2)
    {
        fprintf(stderr, "Too few arguments");
        return 1;
    }

    int sock = socket (PF_UNIX, SOCK_STREAM, 0);

    if (sock == -1)
    {
        fprintf (stderr, "socket() error\n");
        return 1;
    }

    addr.sun_family = AF_UNIX;

    strcpy (addr.sun_path, argv[1]);

    if (bind(sock, (struct sockaddr_un*)&addr, sizeof(&addr)) == -1)
    {
        fprintf (stderr, "bind() error\n");
        return 1;
    }

    fprintf (stderr, "Press <Enter> to continue...");
    fgetc (stdin);

    close (sock);
    unlink(argv[1]);
    return 0;
}