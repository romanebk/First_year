/*
** EPITECH PROJECT, 2024
** organised
** File description:
** displaying
*/

#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include "my.h"

int disp(void *data, char **args)
{
    list_t **list = (list_t **)data;
    list_t *a = *list;

    if (data == NULL)
        return 84;
    if (*list == NULL) {
        mini_printf("The list is empty.\n");
        return 0;
    }
    if (args && args[0])
        return 84;
    while (a != NULL) {
        mini_printf("%s n°%d - \"%s\"\n", a->type, a->id, a->name);
        a = a->next;
    }
    return 0;
}
