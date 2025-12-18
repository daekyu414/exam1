#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>

void sigint_handler(int signum)
{
    pid_t child_pid = fork();

    if(child_pid == 0)
    {
        char* argv[] = {"ls", NULL};
        
        execve("/usr/bin/ls", argv, NULL);
        perror("/usr/bin/ls");
        exit(1);
    }
    else
    {
        int wstatus;

        waitpid(child_pid, &wstatus, 0);
    }
}

void sigquit_handler(int signum)
{
    pid_t child_pid = fork();

    if(child_pid == 0)
    {
        char* argv[] = {"date", NULL};

        execve("/usr/bin/date", argv, NULL);
        perror("/usr/bin/date");
        exit(1);
    }
    else
    {
        int wstatus;

        waitpid(child_pid, &wstatus, 0);
    }
}

void sigalrm_handler(int signum)
{
    pid_t child_pid = fork();

    if(child_pid == 0)
    {
        char* argv[] = {"whoami", NULL};

        execve("/usr/bin/whoami", argv, NULL);
        perror(argv[0]);
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
    struct sigaction sa_int;
    sa_int.sa_handler = sigint_handler;
    sigemptyset(&sa_int.sa_mask);
    sa_int.sa_flags = 0;
    sigaction(SIGINT, &sa_int, NULL);

    struct sigaction sa_quit;
    sa_quit.sa_handler = sigquit_handler;
    sigemptyset(&sa_quit.sa_mask);
    sa_quit.sa_flags = 0;
    sigaction(SIGQUIT, &sa_quit, NULL);

    struct sigaction sa_alrm;
    sa_alrm.sa_handler = sigalrm_handler;
    sigemptyset(&sa_alrm.sa_mask);
    sa_alrm.sa_flags = 0;
    sigaction(SIGALRM, &sa_alrm, NULL);

    alarm(3);
    while(1)
    {
        sleep(1);
    }

    return 0;
}