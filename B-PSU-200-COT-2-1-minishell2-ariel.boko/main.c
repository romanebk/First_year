/*
** EPITECH PROJECT, 2025
** ghjk
** File description:
** gfdsq
*/

#include "my.h"

int main(int argc, char **argv, char **env)
{
    if (argc != 1)
        return 84;
    else if (argc == 1)
        prompt(argv, env);
    else
        return 84;
    return 0;
}
