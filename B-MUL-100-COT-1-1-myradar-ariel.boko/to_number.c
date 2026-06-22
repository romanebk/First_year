/*
** EPITECH PROJECT, 2024
** to_number
** File description:
** returns a number, sent to the function as a string
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int to_number(char *str)
{
    int answer = 0;
    long nb = 0;
    int sign = 1;
    int i = 0;

    for (; str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '-')
            sign = sign * -1;
    }
    for (; str[i] >= '0' && str[i] <= '9'; i++) {
        nb = nb * 10;
        nb = nb + str[i] - '0';
        if (nb > 2147483647 || nb < -2147483648) {
            my_putstr("the number doesn't fit in an integer");
            return 0;
        }
    }
    answer = nb * sign;
    return answer;
}
