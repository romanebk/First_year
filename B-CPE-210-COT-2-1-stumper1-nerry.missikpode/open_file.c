/*
** EPITECH PROJECT, 2024
** dfghjk
** File description:
** hgfd
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char *error_case_one(int fd, char *buffer)
{
    if (fd == -1) {
        free(buffer);
        return NULL;
    }
}

char *error_case_two(int nb_read, int fd, char *buffer)
{
    if (nb_read == -1) {
        close(fd);
        free(buffer);
        return NULL;
    }
}

char *file(char const *filepath)
{
    int fd = 0;
    int nb_read = 0;
    int size = 10000;
    char *buffer = NULL;

    buffer = malloc(sizeof(char) * (size + 1));
    if (buffer == NULL)
        return NULL;
    fd = open(filepath, O_RDONLY);
    error_case_one(fd, buffer);
    nb_read = read(fd, buffer, size);
    error_case_two(nb_read, fd, buffer);
    buffer[size] = '\0';
    close(fd);
    return buffer;
}
