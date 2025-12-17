#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Usage: %s [file name1] [file name2] ... \n", argv[0]);

        return 1;
    }

    int file_num = argc - 1;
    int* fd = (int*)malloc(sizeof(int) * file_num);

    for(int i = 0; i < file_num; i++)
    {
        fd[i] = open(argv[i + 1], O_RDONLY);
        if(fd[i] == -1)
        {
            perror(argv[i + 1]);
        }
        else
        {
            printf("Opened successfully: %s (fd = %d)\n", argv[i + 1], fd[i]);
        }
    }

    for(int i = 0; i < file_num; i++)
    {
        if(fd[i] != -1)
        {
            close(fd[i]);
            printf("Closed successfully: %s\n", argv[i + 1]);
        }
    }

    free(fd);

    return 0;
}