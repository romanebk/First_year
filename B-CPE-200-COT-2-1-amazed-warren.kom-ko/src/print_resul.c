/*
** EPITECH PROJECT, 2025
** functoon
** File description:
** print result
*/

#include "../include/my.h"

void print(char **tab)
{
    for (int i = 0; tab[i]; i++)
        mini_printf("%s\n", tab[i]);
}

void printf_struct(void)
{
    parse_t *var = read_line();

    mini_printf("#number_of_robots\n%d\n", var->nb_robot);
    mini_printf("#rooms\n");
    print(slip_hashtag(var->room));
    mini_printf("#tunnels\n");
    print(slip_hashtag(var->tunnel));
    mini_printf("#moves\n");
    free_function(var->room);
    free_function(var->tunnel);
    free(var);
}
