/*
** EPITECH PROJECT, 2024
** hgfdez
** File description:
** gfds
*/

#include "my.h"

char *info(char *str)
{
    char *buf = NULL;
    char *memtotal = NULL;
    char *retour = NULL;

    buf = file("/proc/meminfo");
    memtotal = strstr(buf, str);
    retour = strtok(memtotal, ":");
    for (int i = 0; i < 1; i++) {
        retour = strtok(NULL, " ");
    }
    return retour;
}

void calcul_mem(void)
{
    double tot_mem = 0.0;
    double mem_free = 0.0;
    double mem_used = 0.0;
    double mem_b_c = 0.0;

    tot_mem = atof(info("MemTotal:")) / 1024;
    mem_free = atof(info("MemFree:")) / 1024;
    mem_used = tot_mem - atof(info("MemAvailable:")) / 1024;
    mem_b_c = (atof(info("Buffers:")) / 1024) + (atof(info("Cached:")) / 1024);
    mem_b_c = mem_b_c + (atof(info("SReclaimable:")) / 1024);
    printw("MiB Mem :  %.1f total,  %.1f free,   ", tot_mem, mem_free);
    printw("%.1f used,   %.1f buff/cache\n", mem_used, mem_b_c);
}

void calcul_swap(void)
{
    double tot_swap = 0.0;
    double swap_free = 0.0;
    double swap_used = 0.0;
    double mem_av = 0.0;

    tot_swap = atof(info("SwapTotal:")) / 1024;
    swap_free = atof(info("SwapFree:")) / 1024;
    swap_used = tot_swap - swap_free;
    mem_av = atof(info("MemAvailable:")) / 1024;
    printw("MiB Swap:  %.1f total,  %.1f free,   ", tot_swap, swap_free);
    printw("%.1f used.   %.1f avail Mem\n", swap_used, mem_av);
}
