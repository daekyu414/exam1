#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Usage: %s [file1 name] ... \n", argv[0]);

        return 1;
    }

    int file_num = argc - 1;
    int* fd_list = (int*)malloc(sizeof(int) * file_num);
    for(int i = 0; i < file_num; i++)
    {
        fd_list[i] = open(argv[i + 1], O_RDONLY);
        if(fd_list[i] == -1)
        {
            perror(argv[i + 1]);
        }
        else
        {
            printf("Opened successfully: %s (fd = %d)\n", argv[i + 1], fd_list[i]);
        }
    }

    for(int i = 0; i < file_num; i++)
    {
        if(fd_list[i] != -1)
        {
            close(fd_list[i]);
            printf("Closed successfully: %s\n", argv[i + 1]);
        }
    }

    free(fd_list);

    return 0;
}