#include <stdio.h>
#include <unistd.h>

int main()
{
    while(1)
    {
        printf("PID: %lu\n", (unsigned long)getpid());
        sleep(1);
    }

    return 0;
}