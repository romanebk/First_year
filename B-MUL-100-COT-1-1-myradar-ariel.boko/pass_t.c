/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** my_radar
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int retour(char **tab)
{
    int i = 0;

    for (; (tab[i] != NULL || tab[i][0] != 'T'); i++);
    return i;
}

passingt_t **pass_t(char **tab, passingt_t **b)
{
    int j = retour(tab);
    passingt_t *node_two;

    for (; tab[j] != NULL; j = j + 3) {
        if (my_strncmp(tab[j], "T", 1) == 0) {
            node_two = malloc(sizeof(passingt_t));
            node_two->tour.x = to_number(tab[j + 1]);
            node_two->tour.y = to_number(tab[j + 2]);
            node_two->r = to_number(tab[j + 3]);
            node_two = *b;
            *b = node_two;
        }
    }
    return b;
}
