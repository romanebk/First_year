/*
** EPITECH PROJECT, 2025
** 107transfer
** File description:
** Main fonctions
*/

#include "../include/my.h"

static char *all_char(char *str, char *wanted)
{
    int len = 0;
    char *all = NULL;

    len = (wanted != NULL) ? strlen(str) + strlen(wanted) + 1
    : strlen(str) + 1;
    all = malloc(sizeof(char) * len);
    if (!all)
        return NULL;
    strcpy(all, str);
    if (wanted != NULL)
        strcat(all, wanted);
    all[len - 1] = '\0';
    return all;
}

void charge_structure(txtc_t *info)
{
    int size = 0;
    char *all = all_char(info->str, info->wanted);

    info->nstr = strdup(filtre_str(all));
    size = strlen(info->nstr) + 1;
    info->var = malloc(sizeof(char_t *) * size);
    for (int i = 0; i < size - 1; i++) {
        info->var[i] = malloc(sizeof(char_t));
        info->var[i]->c = info->nstr[i];
        info->var[i]->occ = count_occur(info->str, info->nstr[i]);
    }
    info->var[size - 1] = NULL;
    if (all != NULL)
        free(all);
    return;
}

static int basic_textcount(txtc_t *info)
{
    if (info->r != 0 || info->t != 0)
        return 0;
    for (int i = 0; info->var[i] != NULL; i++) {
        if (find_char(info->wanted, info->var[i]->c) == 1) {
            printf("%c:%d\n", info->var[i]->c, info->var[i]->occ);
            continue;
        }
    }
    freestruct(info);
    exit(0);
}

static int textcount_t(txtc_t *info)
{
    if (info->r != 0 && info->t == 0)
        return 0;
    tree_t(info);
    for (int i = 0; info->var[i] != NULL; i++) {
        if (find_char(info->wanted, info->var[i]->c) == 1) {
            printf("%c:%d\n", info->var[i]->c, info->var[i]->occ);
            continue;
        }
    }
    freestruct(info);
    exit(0);
}

int text_count(txtc_t *info)
{
    basic_textcount(info);
    textcount_t(info);
    freestruct(info);
    exit(0);
}
