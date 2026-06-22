/*
** EPITECH PROJECT, 2025
** function
** File description:
** clean the spaces which are much
*/

#include "../include/my.h"

char *clean_str(char *str)
{
    int a = 0;
    int c = 0;
    char *buff = NULL;

    buff = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (a = 0; str[a] == 32 || str[a] == '\t' || str[a] == '\n'; a++);
    for (a; str[a] != '\0'; a++) {
        if (str[a] != 32 && str[a] != '\t' && str[a] != '\n') {
            buff[c] = str[a];
            c++;
        }
        if ((str[a] == 32 || str[a] == '\t' || str[a] == '\n') &&
        (str[a + 1] != 32 && str[a + 1] != '\t' && str[a + 1] != '\n'
        && str[a + 1] != '\0')) {
            buff[c] = ' ';
            c++;
        }
    }
    buff[c] = '\0';
    return buff;
}
