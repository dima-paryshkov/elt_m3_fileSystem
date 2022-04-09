#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Error: too few arguments. Write name of directory\n");
        return 1;
    }

    DIR *dir;
    struct dirent *item;
    struct stat *buf;

    buf = (struct stat *)malloc(sizeof(struct stat));

    if ((dir = opendir(argv[1])) == NULL)
    {
        fprintf(stderr, "Error: Can't open dirrectory %s: %s", argv[1], strerror(errno));
        return 1;
    }

    while ((item = readdir(dir)) != NULL)
    {
        if (stat(item->d_name, buf) == -1)
        {
            perror("Error: Can't get information about file");
            return 2;
        }

        fprintf(stdout, "%hhd %9o\t%10s\t%d\t%li\t%li\t%li\n", item->d_type, buf->st_mode, item->d_name, buf->st_uid, buf->st_size, buf->st_blksize, buf->st_blocks);
    }

    fprintf(stdout, "\n");

    if (closedir(dir) == -1)
    {
        perror("Error: Can't close directory");
        return 10;
    }
}