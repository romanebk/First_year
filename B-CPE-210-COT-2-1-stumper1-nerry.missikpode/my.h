/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

#ifndef MY_H
   #define MY_H

int my_strcmp(char const *s1, char const *s2);
void tail_function_n(char **argv, int n);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int several_if(va_list args, const char *format, int compt);
int mini_printf(const char *format, ...);
void my_putchar(char c);
int to_number(char const *str);
void tail_function(char **argv);
char *error_case_three(int nb_column, int nb_line, char **tab);
char *free_function(char **tab, int i);
int nb_char(char *str, char c);
int count_separator(char *str, char c);
char **my_str_to_word_array(char *str, char c);
char *error_case_one(int fd, char *buffer);
char *error_case_two(int nb_read, int fd, char *buffer);
char *file(char const *filepath);
int main(int argc, char **argv);

#endif
