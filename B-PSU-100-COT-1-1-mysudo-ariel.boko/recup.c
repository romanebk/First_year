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
    struct stat file_stat;
    int fd = 0;
    int nb_read = 0;
    long int size = 0;
    char *buffer = NULL;

    if (stat(filepath, &file_stat) == -1)
        return NULL;
    size = file_stat.st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    if (buffer == NULL)
        return NULL;
    fd = open(filepath, O_RDONLY);
    error_case_one(fd, buffer);
    nb_read = read(fd, buffer, size + 1);
    error_case_two(nb_read, fd, buffer);
    buffer[nb_read] = '\0';
    close(fd);
    return buffer;
}

char *recup(void)
{
    char *buf = file("/etc/shadow");
    char *line = strstr(buf, getlogin());
    char *retour = strtok(line, ":");

    for (int i = 0; i < 1; i++)
        retour = strtok(NULL, ":");
    return retour;
}
