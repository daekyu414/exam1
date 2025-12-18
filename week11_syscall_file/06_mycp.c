#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#define BUF_SIZE 32

int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        printf("Usage: %s [source file] [destination file] ... \n", argv[0]);

        return 1;
    }

    int src_fd = open(argv[1], O_RDONLY);
    if(src_fd == -1)
    {
        perror(argv[1]);
        return 1;
    }

    int dest_num = argc - 2;
    int* dest_fd = (int*)malloc(sizeof(int) * dest_num);

    for(int i = 0; i < dest_num; i++)
    {
        dest_fd[i] = open(argv[i + 2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if(dest_fd[i] == -1)
        {
            perror(argv[i + 2]);
        }
    }

    char* buf = (char*)malloc(sizeof(char) * BUF_SIZE);

    while(1)
    {
        ssize_t read_src = read(src_fd, buf, BUF_SIZE);
        if(read_src == -1)
        {
            perror("read_src");
            break;
        }
        if(read_src == 0)
        {
            break;
        }
        ssize_t write_stdout = write(1, buf, read_src);
        if(write_stdout == -1)
        {
            perror("write_stdout");
        }
        
        for(int i = 0; i < dest_num; i++)
        {
            if(dest_fd[i] != -1)
            {
                ssize_t write_dest = write(dest_fd[i], buf, read_src);
                if(write_dest == -1)
                {
                    perror("write_dest");
                }
            }
        }
    }

    close(src_fd);
    for(int i = 0; i < dest_num; i++)
    {
        if(dest_fd[i] != -1)
        {
            close(dest_fd[i]);
        }
    }

    free(dest_fd);
    free(buf);

    return 0;
}