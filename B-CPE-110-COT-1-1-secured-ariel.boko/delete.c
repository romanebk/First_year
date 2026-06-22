/*
** EPITECH PROJECT, 2025
** eecece
** File description:
** tdtdd
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

void complete(Entry_t *current, Entry_t *temp)
{
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp->value);
        free(temp->key);
        free(temp);
    }
}

void delete_hashtable(hashtable_t *ht)
{
    int i = 0;
    Entry_t *current = NULL;
    Entry_t *temp = NULL;

    if (!ht)
        return;
    for (; i < ht->size; i++) {
        current = ht->table[i];
        complete(current, temp);
    }
    free(ht->table);
    free(ht);
}
