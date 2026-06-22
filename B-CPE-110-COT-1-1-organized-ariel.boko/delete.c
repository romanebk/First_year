/*
** EPITECH PROJECT, 2024
** delete
** File description:
** organised
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "shell.h"

void concat(list_t *new_node)
{
    mini_printf("%s n°%d - ", new_node->type, new_node->id);
    mini_printf("\"%s\" deleted.\n", new_node->name);
    free(new_node->type);
    free(new_node->name);
    free(new_node);
}

void cut_sup(list_t *prev, list_t *new_node, list_t **head)
{
    if (prev != NULL) {
        prev->next = new_node->next;
    } else {
        *head = new_node->next;
    }
}

int sup(list_t **head, int idl)
{
    list_t *new_node = *head;
    list_t *prev = NULL;

    while (new_node != NULL) {
        if (new_node->id == idl) {
            cut_sup(prev, new_node, head);
            concat(new_node);
            return 1;
        }
        prev = new_node;
        new_node = new_node->next;
    }
    return 0;
}

int error(char **args, int *idl)
{
    if (!args[0] || !args)
        return 84;
    for (int i = 0; args[i] != NULL; i++) {
        *idl = to_number(args[i]);
        if (*idl < 0)
            return 84;
        if (check_arg(args[i]) == 1)
            return 84;
    }
    return 0;
}

int del(void *data, char **args)
{
    list_t **head = (list_t **)data;
    int idl = 0;
    int ndl = 0;

    if (error(args, &idl) != 0)
        return 84;
    for (int i = 0; args[i] != NULL; i++) {
        idl = to_number(args[i]);
        ndl = sup(head, idl);
        if (ndl == 0)
            return 84;
    }
    return 0;
}
