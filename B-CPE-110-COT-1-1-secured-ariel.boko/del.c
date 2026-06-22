/*
** EPITECH PROJECT, 2025
** c"c
** File description:
** c"rc
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

void complet(hashtable_t *ht, Entry_t *prev, Entry_t *current, int index)
{
    if (prev) {
        prev->next = current->next;
    } else {
        ht->table[index] = current->next;
    }
    free(current->key);
    free(current->value);
    free(current);
}

int ht_delete(hashtable_t *ht, char *key)
{
    int index = 0;
    int hash = 0;
    Entry_t *current = NULL;
    Entry_t *prev = NULL;

    if (!ht || !key || my_strlen(key) == 0)
        return 84;
    hash = ht->hash(key, ht->size);
    index = hash % ht->size;
    current = ht->table[index];
    while (current) {
        if (my_strcmp(current->key, key) == 0) {
            complet(ht, prev, current, index);
            return 0;
        }
        prev = current;
        current = current->next;
    }
    return 84;
}
