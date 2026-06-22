/*
** EPITECH PROJECT, 2024
** fghj$hgfds
** File description:
** hgfds
*/

#include "my.h"

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
    int size = 5000;
    char *buffer = NULL;

    buffer = malloc(sizeof(char *) * size);
    fd = open(filepath, O_RDONLY);
    error_case_one(fd, buffer);
    nb_read = read(fd, buffer, size);
    error_case_two(nb_read, fd, buffer);
    close(fd);
    return buffer;
}
