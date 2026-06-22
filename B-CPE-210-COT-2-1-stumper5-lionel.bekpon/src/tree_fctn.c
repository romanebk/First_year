/*
** EPITECH PROJECT, 2025
** 107transfer
** File description:
** Main fonctions
*/

#include "../include/my.h"

static void swap_char_t(char_t *v, char_t *u)
{
    char_t t;

    if (v->occ < u->occ) {
        t = *v;
        *v = *u;
        *u = t;
    }
}

void tree_t(txtc_t *info)
{
    int i = 0;
    int j = 0;

    for (; info->var[i] != NULL; i++) {
        for (j = 0; info->var[j + 1] != NULL; j++)
            swap_char_t(info->var[j], info->var[j + 1]);
    }
    return;
}

static void swap_char_r(char_t *v, char_t *u)
{
    char_t t;

    if (v->c < u->c) {
        t = *v;
        *v = *u;
        *u = t;
    }
}

void tree_r(txtc_t *info)
{
    int i = 0;
    int j = 0;

    for (; info->var[i] != NULL; i++) {
        for (j = 0; info->var[j + 1] != NULL; j++)
            swap_char_t(info->var[j], info->var[j + 1]);
    }
    return;
}
