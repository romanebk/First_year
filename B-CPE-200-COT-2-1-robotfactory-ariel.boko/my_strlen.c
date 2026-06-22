/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** Counting function
*/

#include "my.h"

int my_s(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}
