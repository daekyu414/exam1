#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Usage: %s <program path> [OPTION] ... \n", argv[0]);

        return 1;
    }

    pid_t child_pid = fork();

    if(child_pid == 0)
    {
        execve(argv[1], &argv[1], NULL);

        perror(argv[1]);
        exit(1);
    }
    else
    {
        int wstatus;

        waitpid(child_pid, &wstatus, 0);
        if(WIFEXITED(wstatus))
        {
            printf("Child exited with status: %d\n", WEXITSTATUS(wstatus));
        }
    }

    return 0;
}