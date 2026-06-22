/*
** EPITECH PROJECT, 2025
** function
** File description:
** count char
*/

#include "../include/my.h"

int my_strlen(const char *\
str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}
