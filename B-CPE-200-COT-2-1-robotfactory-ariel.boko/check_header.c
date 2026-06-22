/*
** EPITECH PROJECT, 2025
** check_name
** File description:
** function
*/

#include "my.h"

char *check_header(char *ptr)
{
    int j = 0;
    int i = 0;
    char *str = opel(ptr);

    if (str == NULL || my_s(str) == 0)
        return NULL;
    if (my_strncmp(str, ".name", 5) != 0)
        return NULL;
    if (my_strncmp(str, ".comment", 8) != 0 ||
        my_strncmp(str, "#comment", 8) != 0)
        return NULL;
    for (; str[i] != '\0'; i++) {
        if (str[i] == '"')
            j++;
        if (str[i] == '"' && str[i + 1] == '"')
            return NULL;
    }
    if (j != 4)
        return NULL;
    return 0;
}
