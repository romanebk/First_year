/*
** EPITECH PROJECT, 2024
** C Pool Day 10
** File description:
** My lib.
*/

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

int error_case(int ac, char **av);
int check(char *str);
char **str_array(char const *str, char sep);
int usage(int ac, char **av);
int check_arg(char *str);
int display(int ac, char **av);
double calculate(double x, int ac, char **av);
double parse_poly(char *str, double x);
void free_function(char **array);

#endif
