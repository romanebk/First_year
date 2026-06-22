/*
** EPITECH PROJECT, 2024
** lkjhg
** File description:
** jhgf
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

int usage(int argc, char **argv)
{
    if (argc == 2) {
        if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
            printf("usage: ./my_sudo -h\n");
            printf("usage: ./my_sudo [-ugEs] [command [args ...]]\n");
        }
    } else {
        return 84;
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return 84;
    if (argc > 2)
        verify_pwd(argc, argv);
    else if (argc == 2 && strcmp(argv[1], "-h") == 0)
        usage(argc, argv);
    else
        return 84;
}
