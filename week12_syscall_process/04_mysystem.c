#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>

int mysystem(char* command)
{
    pid_t child_pid = fork();

    if(child_pid == 0)
    {
        execl("/bin/sh", "sh", "-c", command, NULL);
        perror("execl");
        exit(1);
    }
    else
    {
        int wstatus;

        waitpid(child_pid, &wstatus, 0);
        if(WIFEXITED(wstatus))
        {
            return WEXITSTATUS(wstatus);
        }
        else
        {
            return -1;
        }
    }
}

int main(int argc, char* argv[])
{
    mysystem("ls -l |wc -l");
    mysystem("find . -name '*.c'");

    printf("Good Bye~\n");

    return 0;
}