#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("PID: %lu\n", (unsigned long)getpid());
    printf("PPID: %lu\n", (unsigned long)getppid());

    return 0;
}