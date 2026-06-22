/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** Mini_printf is a first step to
** achieve the project my_printf
*/
// <>

#include "../include/my.h"

static void print_info(txtc_t *info)
{
    printf("%d\n%d\n", info->r, info->t);
    printf("%s\n%s\n", info->str, info->wanted);
    return;
}

int initialisation_ext(txtc_t *info, int *nb, char *arg)
{
    if (arg[0] == '\0')
        return -1;
    if (strcmp(arg, "-r") == 0) {
        info->r = 1;
        return 0;
    }
    if (strcmp(arg, "-t") == 0) {
        info->t = 1;
        return 0;
    }
    if (*nb == 0) {
        info->str = strdup(arg);
        *nb += 1;
        return 0;
    }
    info->wanted = strdup(arg);
    return 0;
}

txtc_t *initialisation(int ac, char *av[])
{
    int nb = 0;
    txtc_t *info = malloc(sizeof(txtc_t));

    info->r = 0;
    info->t = 0;
    info->str = NULL;
    info->var = NULL;
    info->nstr = NULL;
    info->wanted = NULL;
    for (int i = 1; i < ac; i++)
        if (initialisation_ext(info, &nb, av[i]) == -1) {
            freestruct(info);
            exit(84);
        }
    if (info->str == NULL)
        exit(84);
    return info;
}

int main(int ac, char *av[])
{
    txtc_t *info;

    usage(ac, av);
    if (ac >= 2 && ac <= 5) {
        info = initialisation(ac, av);
        charge_structure(info);
        text_count(info);
        return 0;
    }
    return 84;
}
