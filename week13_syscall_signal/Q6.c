#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>

int main()
{
    sigset_t block_set, pending_set;

    sigemptyset(&block_set);
    sigemptyset(&pending_set);
    sigaddset(&block_set, SIGINT);
    sigprocmask(SIG_BLOCK, &block_set, NULL);

    printf("SIGINT blocked. Sleeping for 5 seconds...\n");
    printf("Try ctrl + c during sleep\n");

    sleep(5);

    sigpending(&pending_set);

    if(sigismember(&pending_set, SIGINT))
    {
        printf("\nSIGINT is pending\n");
    }
    else
    {
        printf("\nSIGINT is not pending\n");
    }

    return 0;
}