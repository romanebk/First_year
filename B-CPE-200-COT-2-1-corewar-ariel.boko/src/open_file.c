/*
** EPITECH PROJECT, 2025
** function
** File description:
** open_file
*/

#include "../include/my.h"

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
        printf("read failed\n");
        return NULL;
    }
    if (nb_read == 0) {
        close(fd);
        free(buffer);
        printf("read has nothing more to read\n");
        return NULL;
    }
}

char *file(char const *filepath)
{
    struct stat file_stat;
    int fd = 0;
    int size = 0;
    char *buffer = NULL;

    if (stat(filepath, &file_stat) == -1)
        return NULL;
    size = file_stat.st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    if (buffer == NULL)
        return NULL;
    fd = open(filepath, O_RDONLY);
    error_case_one(fd, buffer);
    read(fd, buffer, size);
    buffer[size] = '\0';
    close(fd);
    return buffer;
}
