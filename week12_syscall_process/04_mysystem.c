#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

int mysystem(char* command)
{
    pid_t child_pid = fork();

    if(child_pid == 0)
    {
        execl("/bin/sh", "sh", "-c", command, NULL);
        perror(command);
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
            return 127;
        }
    }
}

int main()
{
    mysystem("ls -al | wc -l");
    mysystem("find . -name '*.c'");

    printf("Good Bye~\n");

    return 0;
}