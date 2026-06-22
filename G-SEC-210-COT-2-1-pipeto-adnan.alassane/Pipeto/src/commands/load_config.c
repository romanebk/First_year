/*
** EPITECH PROJECT, 2025
** ref-G-SEC-210-project
** File description:
** load_config
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

static char const adminPassword[] = "ThisIsTheBestPassword";

void why_do_i_exist(void)
{
    asm volatile("pop %rdi\n""ret\n");
}

void check_password(char *str)
{
    if (strcmp(str, adminPassword) == 0)
        printf("{Correct password! Welcome, admin.}\n");
}

void load_config(void)
{
    int fd = 0;
    char array[8];

    dprintf(1, "Loading configuration file from ./config.ini\n");
    fd = open("./config.ini", O_RDONLY);
    if (fd == -1) {
        dprintf(2, "Error opening the configuration file\n");
        return;
    }
    if (read(fd, array, sizeof(array)) == -1) {
        dprintf(2, "Error reading from the configuration file\n");
        close(fd);
        return;
    }
    read(fd, array, sizeof(array)) > 0 ? dprintf(1,
    "Successfully read configuration: %.*s\n",
    (int)read(fd, array, sizeof(array)), array) : dprintf(2,
    "No data read from the configuration file\n");
    close(fd);
    return;
}
