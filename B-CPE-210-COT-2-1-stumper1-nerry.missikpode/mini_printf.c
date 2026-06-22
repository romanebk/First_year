/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** Certain behaviors of the printf function
*/

#include "my.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int a = 0;

    for (; str[a] != '\0'; a++) {
        my_putchar(str[a]);
    }
}

int my_put_nbr(int nb)
{
    if (nb <= -1) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
}

int several_if(va_list args, const char *format, int compt)
{
    if (format[compt + 1] == 'd' || format[compt + 1] == 'i')
        my_put_nbr(va_arg(args, int));
    if (format[compt + 1] == 's')
        my_putstr(va_arg(args, char *));
    if (format[compt + 1] == 'c')
        my_putchar(va_arg(args, int));
    if (format[compt + 1] == '%')
        my_putchar('%');
}

int mini_printf(const char *format, ...)
{
    va_list args;
    int compt = 0;

    va_start(args, format);
    for (; format[compt] != '\0'; compt++) {
        if (format[compt] == '%') {
            several_if(args, format, compt);
            compt++;
        } else {
            my_putchar(format[compt]);
        }
    }
    va_end(args);
}
