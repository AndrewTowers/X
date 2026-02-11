#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define READ_SIZE 1024

static void print_error(const char *msg)
{
    fprintf(stderr, "Error: ");
    perror(msg);
}

int main(int argc, char **argv)
{
    if (argc != 2 || argv[1][0] == '\0')
        return 1;
    char *to_find = argv[1];
    size_t len_find = strlen(to_find);
    char buffer[READ_SIZE];
    char *data = NULL;
    size_t total = 0;
    ssize_t bytes;

    while ((bytes = read(STDIN_FILENO, buffer, READ_SIZE)) > 0)
    {
        char *tmp = realloc(data, total + bytes);
        if (!tmp)
        {
            free(data);
            print_error("malloc");
            return 1;
        }
        data = tmp;
        memmove(data + total, buffer, bytes);
        total += bytes;
    }
    if (bytes < 0)
    {
        print_error("read");
        free(data);
        return 1;
    }
    if (len_find > 0 && data)
    {
        char *pos = data;
        while ((pos = memmem(pos, total - (pos - data), to_find, len_find)))
        {
            memset(pos, '*',len_find);
            pos += len_find;
        }
    }
    if (data && total > 0)
        write(STDOUT_FILENO, data, total);
    free(data);
    return 0;
}