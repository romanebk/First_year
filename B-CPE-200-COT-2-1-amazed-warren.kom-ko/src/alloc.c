/*
** EPITECH PROJECT, 2025
** function
** File description:
** alloc and free
*/

#include "../include/my.h"

parse_t *alloc_struct(void)
{
    parse_t *var = malloc(sizeof(parse_t));

    if (!var)
        return NULL;
    var->room = malloc(sizeof(char *) * 100);
    var->tunnel = malloc(sizeof(char *) * 100);
    if (!var->room || !var->tunnel) {
        free(var->room);
        free(var->tunnel);
        free(var);
        return NULL;
    }
    var->nb_robot = 0;
    return var;
}

void free_function(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}
