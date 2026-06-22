/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my.h
*/

#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef MY_H
    #define MY_H

int file_d(char const *str);
char *error_case_three(char *buffer);
int my_strncmp(char const *s1, char const *s2, int n);
char *check_header(char *ptr);
int count_se(char *str, char c);
int count_sep(char *str);
int get_param_size(char type, int is_index);
int swap(int value);
int main(int ac, char **av);
unsigned int move(unsigned int ma);
char **my_st(char *str, char c);
char **my_str(char *str);
char *opel(char const *str);
void my_strncpy(char *dest, char const *src, int n);
void my_strcat(char *dest, char *src);
int my_s(char const *str);
void my_strcpy(char *dest, char const *src);
int prog_size(char **tab);
char *recup(char *str, int n);
char *name(char *str);

#endif
