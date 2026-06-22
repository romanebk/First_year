/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** Prototype
*/

#include <stdarg.h>

#ifndef MY_H
    #define MY_H
    #include <stdio.h>
    #include <unistd.h>
    #include <ctype.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <sys/stat.h>
    #include <sys/wait.h>
    #include <sys/types.h>

typedef struct my_array_t {
    int len;
    int car;
    int z;
    int y;
    char **table;
} array_t;

int check(char *av);
int count(char **av);
char **str_to_word_array(char *str, char c, int i);
char **remplace(char **tab, char *line, char c);
int count(char **av);
int check(char *av);
char printf_player(int i, char x, char o);
int launch_loop(int def, char x, char o);
int main(int ac, char **av);
char **alloc_arr(int size);
void print_grid(char **tab, int def);
char **create_grid(char a, int def);
int my_strlen(char const *str);
#endif // MY_H
