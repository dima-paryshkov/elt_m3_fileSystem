#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int fd;
    char *buf = "Have a good day :) _ From 10.04.2022"; 
    int lenBuf = strlen(buf);
    char *bufIn = (char*)malloc(lenBuf + 1);

    if ((fd  = open("file.txt", O_CREAT | O_RDWR, 0666)) == -1)
    {
        perror("open");
        return 1;
    }

    int err;

    err = write(fd, (void*)buf, lenBuf);
    if (err == -1)
    {
        perror("write");
        return 2;
    }
    else if (err < lenBuf) 
    {
        fprintf(stderr, "Warning: write() write not all bytes\n");
    }

    if (lseek(fd, (off_t)0, SEEK_SET) == (off_t) -1)
    {
        perror("lseek");
        return 3;
    }

    err = read(fd, (void*)bufIn, lenBuf);
    if (err == -1)
    {
        perror("read");
        return 5;
    }
    else if (err < lenBuf) 
    {
        fprintf(stderr, "Warning: read() read not all bytes\n");
    }

    printf("Write: %s\n", buf);
    printf("Read: %s\n", bufIn);

    if (close(fd) == -1)
    {
        perror("close");
        return 6;
    }

    return 0;
}