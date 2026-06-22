/*
** EPITECH PROJECT, 2025
** function
** File description:
** behavior of tail
*/

#include "my.h"

void print_elem(int i, char **tab)
{
    for (; tab[i] != NULL; i++) {
        mini_printf("%s\n", tab[i]);
        free(tab[i]);
    }
}

void tail_function(char **argv)
{
    int i = 0;
    char *content = NULL;
    char **tab = NULL;

    content = file(argv[1]);
    tab = my_str_to_word_array(content, '\n');
    for (; tab[i] != NULL; i++);
    if (i + 1 <= 10) {
        i = 0;
        print_elem(i, tab);
    } else if (i + 1 > 10) {
            i = i - 10;
            print_elem(i, tab);
        }
    free(tab);
    free(content);
}

void tail_function_n(char **argv, int n)
{
    int i = 0;
    char *content = NULL;
    char **tab = NULL;

    content = file(argv[3]);
    tab = my_str_to_word_array(content, '\n');
    for (; tab[i] != NULL; i++);
    i = i - n;
    print_elem(i, tab);
    free(tab);
    free(content);
}
