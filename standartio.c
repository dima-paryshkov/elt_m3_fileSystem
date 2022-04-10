#define _XOPEN_SOURCE 500
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
    char *bufAdd = "Some addition";
    int lenBuf = strlen(buf);

    char *bufIn = (char *)malloc(lenBuf + 1);

    if ((fd = open("file", O_CREAT | O_RDWR, 0666)) == -1)
    {
        perror("open");
        return 1;
    }

    ssize_t err;

    err = write(fd, (void *)buf, lenBuf);
    if (err == (ssize_t)-1)
    {
        perror("write");
        return 2;
    }
    else if (err < lenBuf)
    {
        fprintf(stderr, "Warning: write() write not all bytes\n");
    }

    if (lseek(fd, (off_t)0, SEEK_SET) == (off_t)-1)
    {
        perror("lseek");
        return 3;
    }

    err = read(fd, (void *)bufIn, lenBuf);
    if (err == (ssize_t)-1)
    {
        perror("read");
        return 4;
    }
    else if (err < lenBuf)
    {
        fprintf(stderr, "Warning: read() read not all bytes\n");
    }

    printf("write: %s\n", buf);
    printf("read: %s\n\n", bufIn);

    err = pwrite(fd, (void *)bufAdd, strlen(bufAdd), (off_t)(lenBuf));
    if (err == (ssize_t)-1)
    {
        perror("pwrite");
        return 5;
    }
    else if (err < strlen(bufAdd))
    {
        fprintf(stderr, "Warning: pwrite() write not all bytes\n");
    }

    memset(bufIn, 0, strlen(bufIn));

    err = pread(fd, (void *)bufIn, strlen(bufAdd), (off_t)(lenBuf));
    if (err == (ssize_t)-1)
    {
        perror("pread");
        return 6;
    }
    else if (err < strlen(bufAdd))
    {
        fprintf(stderr, "Warning: pread() read not all bytes\n");
    }

    if (close(fd) == -1)
    {
        perror("close");
        return 7;
    }

    printf("pwrite: %s\n", bufAdd);
    printf("pread: %s\n", bufIn);

    free(bufIn);
    return 0;
}