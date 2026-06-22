/*
** EPITECH PROJECT, 2024
** lkjhg
** File description:
** mlkj
*/

#include "my.h"

int getload(double *loadavg, int nb_el)
{
    int i = 0;
    char *el = NULL;
    char *load_el = NULL;

    el = file("/proc/loadavg");
    load_el = strtok(el, " ");
    while (i < nb_el && loadavg != NULL) {
        loadavg[i] = atof(load_el);
        load_el = strtok(NULL, " ");
        i++;
    }
    free(el);
    return 0;
}
