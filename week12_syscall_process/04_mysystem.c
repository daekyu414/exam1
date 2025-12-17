#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

int mysystem(char* cmd)
{
    pid_t child_pid = fork();

    if(child_pid == 0)
    {
        execl("/bin/sh", "sh", "-c", cmd, NULL);
        perror("/bin/sh");
        exit(1);
    }
    else
    {
        int wstatus;

        waitpid(child_pid, &wstatus, 0);
    }
}

int main()
{
    mysystem("ls -l | wc -l");
    mysystem("find . -name '*.c'");

    printf("Good Bye~\n");

    return 0;
}