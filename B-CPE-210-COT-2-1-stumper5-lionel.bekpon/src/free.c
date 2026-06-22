/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** Mini_printf is a first step to
** achieve the project my_printf
*/
// <>

#include "../include/my.h"

int freestruct(txtc_t *info)
{
    int i = 0;

    if (info == NULL)
        return 0;
    if (info->nstr != NULL)
        free(info->nstr);
    if (info->str != NULL)
        free(info->str);
    if (info->wanted != NULL)
        free(info->wanted);
    if (info->var != NULL) {
        for (i = 0; info->var[i] != NULL; i++)
            free(info->var[i]);
        free(info->var[i]);
        free(info->var);
    }
    free(info);
}
