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

int my_exec(char *w1, char **w2)
{
    return execvp(w1, w2);
}
