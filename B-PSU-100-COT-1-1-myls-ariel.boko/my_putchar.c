/*
** EPITECH PROJECT, 2024
** my_putchar
** File description:
** Displaying the character
*/

#include "my.h"
#include <stdio.h>
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
