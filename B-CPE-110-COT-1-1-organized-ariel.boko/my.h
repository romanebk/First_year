/*
** EPITECH PROJECT, 2024
** sdfghjkl
** File description:
** qwxcvbn
*/

#include <stdint.h>

#ifndef _MY_H_
    #define _MY_H_

typedef struct list_s {
    void *data;
    int id;
    char *name;
    char *type;
    int *ndl;
    struct list_s *next;
} list_t;

void cut_sup(list_t *prev, list_t *new_node, list_t **head);
void concat(list_t *new_node);
int sup(list_t **head, int idl);
int error_sort(char **args);
int check_arg(char *str);
int free_error(list_t *new_node);
void cut_add(list_t *new_node);
int id_void(list_t *new_node, int id_del, int i);
int free_elem(list_t *new_node, int id_del, list_t *prev, list_t **head);
int condition(char **args, int i);
int to_number(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char const *src);
int my_strlen(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int mini_printf(const char *format, ...);
int main(int argc, char **argv);

#endif
