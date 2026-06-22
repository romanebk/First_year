/*
** EPITECH PROJECT, 2024
** C Pool Day 10
** File description:
** My lib.
*/

#include <stdbool.h>
#include "utilities/mini.h"
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

int str_isnumber(char *str);
char to_upper(char c);
int my_str_islower(char *str);
int square_root(int nb);
bool is_in_grid(char *haystack, char *needle);
void print_grid(char **tab, int def);
char **create_grid(char *str, int def);
void grid_solver(char **tab, char *hay, char *ne, int def);

#endif
