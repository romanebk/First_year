/*
** EPITECH PROJECT, 2025
** open
** File description:
** file
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "op.h"
#include "my.h"

int file_d(char const *str)
{
    int fd = open(str, O_RDONLY);

    return fd;
}

char *opel(char const *str)
{
    struct stat f;
    int fd = file_d(str);
    char *buf;

    stat(str, &f);
    buf = malloc(sizeof(char) * f.st_size + 1);
    read(fd, buf, f.st_size);
    return buf;
}
