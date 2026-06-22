/*
** EPITECH PROJECT, 2024
** C Pool Day 10
** File description:
** My lib.
*/

#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <stddef.h>

#ifndef MY_H
    #define MY_H

int check_arg(char *str);
int usage(int ac, char **av);
double borwein_function(double x, int n);
void midpoint_function(int n);
void trapezoidal_function(int n);
void simpson_function(int n);
int main(int ac, char **av);

#endif
