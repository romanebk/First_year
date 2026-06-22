/*
** EPITECH PROJECT, 2024
** FUNCTION
** File description:
** Verify argument
*/

#include "shell.h"
#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int check_arg(char *str)
{
    int i = 0;
    int res = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9' || str[i] == '-' || str[i] == '+') {
            res = 0;
        } else {
            res = 1;
            break;
        }
        i++;
    }
    return res;
}
