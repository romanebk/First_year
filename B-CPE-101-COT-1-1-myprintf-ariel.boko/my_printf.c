/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** The implementation of the printf function
*/

#include "include/my.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int several_if_one(va_list args, const char *format, int compt)
{
    if (format[compt + 1] == 'f')
        my_put_nbr_f(va_arg(args, double));
    if (format[compt + 1] == 'd' || format[compt + 1] == 'i')
        my_put_nbr(va_arg(args, int));
    if (format[compt + 1] == 's')
        my_putstr(va_arg(args, char *));
    if (format[compt + 1] == 'c')
        my_putchar(va_arg(args, int));
    if (format[compt + 1] == '%')
        my_putchar('%');
    if (format[compt + 1] == 'e')
        my_put_nbr_e(va_arg(args, double));
}

int several_if_two(va_list args, const char *format, int compt)
{
    if (format[compt + 1] == 'F')
        my_put_nbr_f(va_arg(args, double));
    if (format[compt + 1] == 'u')
        my_put_nbr_unsigned(va_arg(args, unsigned int));
    if (format[compt + 1] == 'o')
        my_put_nbr_base_o(va_arg(args, int));
    if (format[compt + 1] == 'x')
        my_put_nbr_xp(va_arg(args, int));
    if (format[compt + 1] == 'X')
        my_put_nbr_xg(va_arg(args, unsigned int));
    if (format[compt + 1] == 'p') {
        my_putstr("0x");
        my_put_nbr_p(va_arg(args, unsigned long));
    }
}

int my_printf(const char *format, ...)
{
    va_list args;
    int compt = 0;

    va_start(args, format);
    for (; format[compt] != '\0'; compt++) {
        if (format[compt] == '%') {
            several_if_one(args, format, compt);
            several_if_two(args, format, compt);
            compt++;
        } else {
            my_putchar(format[compt]);
        }
    }
    va_end(args);
    return 0;
}
