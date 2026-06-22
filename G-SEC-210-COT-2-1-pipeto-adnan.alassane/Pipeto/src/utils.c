/*
** EPITECH PROJECT, 2025
** function
** File description:
** utils
*/

#include "ansi-colors.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

void write_color(int fd, const char *color, const char *str)
{
    if (fd < 0 || !color || !str)
        return;
    dprintf(fd, "%s%s%s", color, str, CRESET);
    write(1, "> ", 3);
}

FILE *try_open_rc_file(void)
{
    char *home = NULL;
    FILE *file = fopen(".pipetorc", "r");
    char home_rc[1024];

    if (!file) {
        home = getenv("HOME");
        if (home) {
            snprintf(home_rc, sizeof(home_rc), "%s/.pipetorc", home);
            file = fopen(home_rc, "r");
        }
    }
    return file;
}

void process_rc_line(char *line)
{
    char cmd[1100];

    if (line[0] == '#' || line[0] == '\n')
        return;
    line[strcspn(line, "\n")] = '\0';
    if (strncmp(line, "exec ", 5) == 0) {
        snprintf(cmd, sizeof(cmd), "%s", line + 5);
        system(cmd);
    } else {
        printf("Pipeto command: ");
        printf("%s\n", line);
    }
}

void load_pipetorc(void)
{
    FILE *rc_file = try_open_rc_file();
    char line[1024];

    if (!rc_file)
        return;
    while (fgets(line, sizeof(line), rc_file)) {
        process_rc_line(line);
    }
    fclose(rc_file);
}
