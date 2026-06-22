/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** Displaying a string of characters
*/

#include "include/my.h"
#include <unistd.h>
#include <stdio.h>

int my_putstr(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        my_putchar(str[a]);
        a++;
    }
    return 0;
}
