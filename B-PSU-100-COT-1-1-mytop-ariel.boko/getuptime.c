/*
** EPITECH PROJECT, 2024
** lkjh
** File description:
** gfs
*/

#include "my.h"

int *getuptime(double *uptime, int nb_el)
{
    temp_t tm;
    int i = 0;
    char *el = NULL;
    char *uptime_el = NULL;

    el = file("/proc/uptime");
    uptime_el = strtok(el, " ");
    while (i < nb_el && uptime != NULL) {
        uptime[i] = atof(uptime_el);
        uptime_el = strtok(NULL, " ");
        i++;
    }
    free(el);
    return 0;
}
