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

passinga_t **pass_a(char **tab, passinga_t **a)
{
    passinga_t *node_one = NULL;

    for (int i = 0; tab[i] != NULL; i = i + 7) {
        if (tab[i][0] == 'A') {
            node_one = malloc(sizeof(passinga_t));
            node_one->i.x = to_number(tab[i + 1]);
            node_one->i.y = to_number(tab[i + 2]);
            node_one->f.x = to_number(tab[i + 3]);
            node_one->f.y = to_number(tab[i + 4]);
            node_one->v = to_number(tab[i + 5]);
            node_one->dur = to_number(tab[i + 6]);
            node_one = *a;
            *a = node_one;
        }
    }
    return a;
}
