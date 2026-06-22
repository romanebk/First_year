/*
** EPITECH PROJECT, 2025
** function
** File description:
** my.h
*/

#include <stdbool.h>
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
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#ifndef MY_H
    #define MY_H

typedef struct {
    int nb_robot;
    char **room;
    char **tunnel;
} parse_t;

typedef struct parse_context {
    int j;
    int i;
    int e;
} parse_context_t;

int mini_printf(const char *format, ...);
parse_t *read_line(void);
void free_function(char **tab);
parse_t *alloc_struct(void);
void printf_struct(void);
char **slip_hashtag(char **tab);
char *my_strtok(char *str, const char *delim);
char *my_strchr(const char *s, int c);
int my_strlen(char const *str);
int check_space(char *str);
int chech_tiret(char *str);
int check_arg(char *str);
void ommit(char *str1);
int my_wordlen(char const *str, char sep);
char **alloc(char const *str, char sep, char **r);
char **str_array(char const *str, char sep);
int to_number(char const *str);
int my_wordlen(char const *str, char sep);
char **alloc(char const *str, char sep, char **r);
char **str_array(char const *str, char sep);
int my_strlen(char const *str);
char *clean_str(char *str);
char *my_strdup(char const *src);

#endif
