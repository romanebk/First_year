/*
** EPITECH PROJECT, 2025
** open
** File description:
** mz
*/

#include "../include/my.h"

char *open_file(char const *filepath)
{
    int fd;
    struct stat info;
    char *buffer = NULL;

    if (stat(filepath, &info) == -1) {
        return NULL;
    }
    buffer = malloc((info.st_size + 1) * sizeof(char));
    if (!buffer)
        return NULL;
    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        printf("FAILURE\n");
        free(buffer);
        return NULL;
    }
    read(fd, buffer, info.st_size);
    buffer[info.st_size] = '\0';
    close(fd);
    return buffer;
}
