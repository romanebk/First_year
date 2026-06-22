/*
** EPITECH PROJECT, 2024
** my_ls
** File description:
** Behavior of ls function
*/

#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>
#include "my.h"

void my_ls(const char *dir, int op_a)
{
    DIR *p = opendir(dir);
    struct dirent *d;

    if (p == NULL) {
        perror("opendir");
        return;
    }
    while (1) {
        d = readdir(p);
        if (d == NULL)
            break;
        if (!op_a && d->d_name[0] == '.')
            continue;
        my_putstr(d->d_name);
        my_putstr("  ");
    }
    closedir(p);
    my_putchar('\n');
}

int main(int argc, char **argv)
{
    int op_a = 0;
    int i = 1;

    if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'a') {
        op_a = 1;
        i = 2;
    }
    if (argc == 1 || (argc == 2 && op_a)) {
        my_ls(".", op_a);
    } else {
        for (; i < argc; i++) {
            my_ls(argv[i], op_a);
        }
    }
    return 0;
}
