/*
** EPITECH PROJECT, 2025
** function
** File description:
** write to output
*/

#include "my.h"

void my_putchar_error(char c)
{
    write(2, &c, 1);
}

int my_putstr_error(char const *str)
{
    int a = 0;

    for (; str[a] != '\0'; a++)
        my_putchar_error(str[a]);
    return 0;
}
