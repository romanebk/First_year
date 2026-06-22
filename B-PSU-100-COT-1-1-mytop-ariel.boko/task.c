/*
** EPITECH PROJECT, 2024
** fghj$hgfds
** File description:
** hgfds
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>
#include "my.h"

task_t cond(task_t line, char *buffer, int i)
{
    for (; buffer[i] != '\0'; i++) {
        if (buffer[i] == 'S' || buffer[i] == 'I')
            line.sleep++;
        if (buffer[i] == 'T')
            line.stop++;
        if (buffer[i] == 'Z')
            line.zomb++;
        if (buffer[i] == 'R')
            line.run++;
    }
    return line;
}

task_t cut_run(char *str, task_t line)
{
    char src[1000] = "/proc/";
    int fd = 0;
    int nb_read = 0;
    int i = 0;
    char buffer[101];

    strcat(src, str);
    strcat(src, "/stat");
    fd = open(src, O_RDONLY);
    error_case_one(fd, buffer);
    nb_read = read(fd, buffer, 98);
    error_case_two(nb_read, fd, buffer);
    buffer[nb_read] = '\0';
    for (; buffer[i] != ')'; i++);
    line = cond(line, buffer, i);
    close(fd);
    return line;
}

int line_task(void)
{
    int task = 0;
    task_t line = {0, 0, 0, 0};
    DIR *f = NULL;
    struct dirent *g = NULL;

    f = opendir("/proc");
    if (f == NULL)
        return 84;
    g = readdir(f);
    while (g != NULL) {
        if (g->d_name[0] >= '0' && g->d_name[0] <= '9') {
            task++;
            line = cut_run(g->d_name, line);
        }
        g = readdir(f);
    }
    closedir(f);
    printw("Tasks: %d total,   %d running, ", task, line.run);
    printw("%d sleeping,   %d stopped,  ", line.sleep, line.stop);
    printw("%d zombie\n", line.zomb);
}
