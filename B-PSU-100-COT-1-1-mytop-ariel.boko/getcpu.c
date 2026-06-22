/*
** EPITECH PROJECT, 2024
** function
** File description:
** function
*/

#include "my.h"

double *getcpu(void)
{
    int i = 0;
    char *buf = NULL;
    char *line_cpu = NULL;
    double *cpu = NULL;

    buf = file("/proc/stat");
    line_cpu = strtok(buf, " ");
    cpu = malloc(sizeof(double) * 9);
    line_cpu = strtok(NULL, " ");
    for (int i = 0; i < 8; i++) {
        cpu[i] = atof(line_cpu) / 100;
        line_cpu = strtok(NULL, " ");
    }
    free(buf);
    return cpu;
}

double *result(void)
{
    double *val;
    double *tab = {0};
    double *tab1 = {0};
    int i = 0;
    int j = 0;

    tab = getcpu();
    sleep(1);
    tab1 = getcpu();
    val = malloc(sizeof(double) * 9);
    while (i < 8) {
        val[j] = (tab1[i] - tab[i]);
        i++;
        j++;
    }
    free(tab);
    free(tab1);
    return val;
}

void display_cpu(void)
{
    int i = 0;
    double *tab = result();

    printw("%%Cpu(s):  %.1f us,  %.1f sy,  ", tab[0], tab[1]);
    printw("%.1f ni, %.1f id,", tab[2], tab[3]);
    printw("  %.1f wa,  %.1f hi,", tab[4], tab[5]);
    printw("  %.1f si,  %.1f st\n", tab[6], tab[7]);
    free(tab);
}
