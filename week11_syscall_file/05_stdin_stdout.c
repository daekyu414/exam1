#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 128

int main(int argc, char* argv[])
{
    if(argc != 1)
    {
        printf("Usage: %s\n", argv[0]);

        return 1;
    }

    char* buf = (char*)malloc(sizeof(char) * BUF_SIZE);

    while(1)
    {
        ssize_t read_stdin = read(0, buf, BUF_SIZE);
        if(read_stdin == -1)
        {
            perror("read_stdin");
            break;
        }
        if(read_stdin == 0)
        {
            printf("Detected EOF (Ctrl + D)\n");
            break;
        }
        ssize_t write_stdout = write(1, buf, read_stdin);
        if(write_stdout == -1)
        {
            perror("write_stdout");
            break;
        }
    }

    free(buf);

    return 0;
}