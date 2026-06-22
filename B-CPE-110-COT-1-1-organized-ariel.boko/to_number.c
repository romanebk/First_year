/*
** EPITECH PROJECT, 2024
** function
** File description:
** function
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "my.h"

int to_number(char const *str)
{
    int answer = 0;
    long nb = 0;
    int sign = 1;
    int i = 0;

    for (; str[i] == ' ' || str[i] == '\t' || str[i] == '\n'; i++);
    for (; str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '-')
            sign = sign * -1;
    }
    for (; str[i] >= '0' && str[i] <= '9'; i++) {
        nb = nb * 10 + str[i] - '0';
        if (nb > 2147483647 || nb < -2147483648)
            return 0;
    }
    answer = nb * sign;
    return answer;
}
