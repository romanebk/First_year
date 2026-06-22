/*
** EPITECH PROJECT, 2025
** function
** File description:
** chech if the number is a interger
*/

#include "../include/dataframe.h"

int uns_integer(char *str)
{
    int i = 0;
    int ret = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            ret = 1;
        } else
            ret = -1;
    }
    return ret;
}

int is_integer(char *str)
{
    int i = 0;
    int ret = 0;

    if (str[0] == '-')
        i = i + 1;
    for (; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            ret = 1;
        } else
            ret = -1;
    }
    return ret;
}

int is_float(char *str)
{
    int i = 0;
    int j = 0;
    int a = 0;
    int ret = 0;

    if (str[0] == '-')
        i = i + 1;
    for (; str[j] != '\0'; j++) {
        if (str[j] == '.')
            a++;
    }
    if (strlen(str) < 3 || str[0] == '.' || str[j] == '.')
        return 0;
    for (; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            ret = 1;
        } else
            ret = -1;
    }
    return ret;
}

int is_bool(char *str)
{
    if (strcmp(str, "true") == 0 || strcmp(str, "false") == 0)
        return 1;
    return 0;
}
