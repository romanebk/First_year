/*
** EPITECH PROJECT, 2024
** organized
** File description:
** function add
*/

#include <string.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include "my.h"

int error_case(char **args)
{
    int i = 0;

    for (; args[i] != NULL; i = i + 2) {
        if (my_strcmp(args[i], "ACTUATOR") != 0 &&
        my_strcmp(args[i], "WIRE") != 0 &&
        my_strcmp(args[i], "DEVICE") != 0 &&
        my_strcmp(args[i], "PROCESSOR") != 0 &&
        my_strcmp(args[i], "SENSOR") != 0) {
            break;
            return 84;
        }
        if (args[i + 1] == NULL) {
            return 84;
        }
    }
    return 0;
}

int free_error(list_t *new_node)
{
    if (new_node->type == NULL || new_node->name == NULL) {
        free(new_node);
        return 84;
    }
}

void cut_add(list_t *new_node)
{
    mini_printf("%s n°%d - ", new_node->type, new_node->id);
    mini_printf("\"%s\" added.\n", new_node->name);
}

int add(void *data, char **args)
{
    static int id = 0;
    list_t *new_node;
    list_t **head = (list_t **)data;

    if (new_node == NULL || error_case(args) || !args[0])
        return 84;
    for (int j = 0; args[j] != NULL; j = j + 2) {
        new_node = malloc(sizeof(list_t));
        if (new_node == NULL)
            return 84;
        new_node->id = id++;
        new_node->type = my_strdup(args[j]);
        new_node->name = my_strdup(args[j + 1]);
        free_error(new_node);
        new_node->next = *head;
        *head = new_node;
        cut_add(new_node);
    }
    return 0;
}

int main(int argc, char **argv)
{
    list_t *a = NULL;

    if (argc != 1)
        return 84;
    if (workshop_shell(&a) == 84)
        return 84;
    return 0;
}
