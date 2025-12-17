#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>

struct two_double
{
    double a;
    double b;
}data;

void sigalrm_handler(int signum)
{
    printf("%f, %f\n", data.a, data.b);
    alarm(1);
}

int main()
{
    struct two_double zeros = {0.0, 0.0}, ones = {1.0, 1.0};

    struct sigaction sa_alrm;
    sa_alrm.sa_handler = sigalrm_handler;
    sigemptyset(&sa_alrm.sa_mask);
    sa_alrm.sa_flags = 0;
    sigaction(SIGALRM, &sa_alrm, NULL);

    sigset_t block_set;
    sigemptyset(&block_set);
    sigaddset(&block_set, SIGALRM);


    alarm(1);
    while(1)
    {
        sigprocmask(SIG_BLOCK, &block_set, NULL);
        data = ones;
        sigprocmask(SIG_UNBLOCK, &block_set, NULL);

        sigprocmask(SIG_BLOCK, &block_set, NULL);
        data = zeros;
        sigprocmask(SIG_UNBLOCK, &block_set, NULL);
    }

    return 0;
}