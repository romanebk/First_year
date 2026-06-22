/*
** EPITECH PROJECT, 2025
** function
** File description:
** check tiret and space
*/

#include "../include/my.h"

int chech_tiret(char *str)
{
    char *tmp = NULL;
    int ret = 0;

    tmp = clean_str(str);
    for (int i = 0; tmp[i] != '\0'; i++) {
        if (i != 0 && tmp[i] == '-')
            ret += 1;
    }
    if (ret == 1)
        return 1;
    else
        return 2;
    free(tmp);
    return 0;
}

int check_space(char *str)
{
    char *tmp = NULL;
    int ret = 0;

    tmp = clean_str(str);
    for (int i = 0; tmp[i] != '\0'; i++) {
        if (tmp[i] == ' ')
            ret += 1;
    }
    if (ret == 2)
        return 1;
    else
        return 2;
    free(tmp);
    return 0;
}
