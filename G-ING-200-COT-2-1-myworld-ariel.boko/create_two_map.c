/*
** EPITECH PROJECT, 2025
** create an array of sfvector
** File description:
** function
*/

#include "my.h"

sfVector2f **create_2d_map(int **map)
{
    sfVector2f **tab = NULL;
    int a = 0;
    int b = 0;

    tab = malloc(sizeof(sfVector2f *) * (MAP_Y + 1));
    if (!tab)
        return NULL;
    for (; a < MAP_Y; a++) {
        tab[a] = malloc(sizeof(sfVector2f) * (MAP_X + 1));
        for (; b < MAP_Y; b++) {
            tab[a][b] = project_iso_point(a * 100, b * 100, map[a][b] * 100);
        }
    }
    tab[MAP_Y] = NULL;
    return tab;
}
