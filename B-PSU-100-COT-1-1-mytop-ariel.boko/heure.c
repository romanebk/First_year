/*
** EPITECH PROJECT, 2024
** fghjkl
** File description:
** gfds
*/

#include "my.h"

int heure(void)
{
    time_t t = time(NULL);
    struct tm *a = localtime(&t);

    if (a) {
    mvprintw(0, 0, "top - %02d:%02d:%02d", a->tm_hour, a->tm_min, a->tm_sec);
    }
}
