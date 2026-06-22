/*
** EPITECH PROJECT, 2025
** Robot factory
** File description:
** macro file.
*/

#ifndef MINI_H_
        #include <unistd.h>
        #define MINI_H_

int my_putnbr(int nb);
int my_putstr(char *str, int fd);
int my_strlen(char *str);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
char *my_strdup(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char *s1, char *s2, int n);
int my_getnbr(char *str);

#endif
