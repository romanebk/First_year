/*
** EPITECH PROJECT, 2025
** ghjklm
** File description:
** hgfds
*/

#include "my.h"

int print_env(char **env)
{
    for (char **e = env; *e != NULL; e++)
        mini_printf("%s\n", *e);
    return 0;
}
