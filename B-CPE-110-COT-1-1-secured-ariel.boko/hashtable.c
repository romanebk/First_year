/*
** EPITECH PROJECT, 2025
** v"rg"
** File description:
** "g"'g"'g"'
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    int i = 0;
    hashtable_t *ht = malloc(sizeof(hashtable_t));

    if (hash == NULL || len <= 1 || !hash)
        return NULL;
    ht = malloc(sizeof(hashtable_t));
    if (ht == NULL)
        return NULL;
    ht->table = malloc(sizeof(Entry_t *) * len);
    if (!ht->table) {
        free(ht);
        return NULL;
    }
    for (; i < len; i++)
        ht->table[i] = NULL;
    ht->size = len;
    ht->hash = hash;
    return ht;
}

char *ht_search(hashtable_t *ht, char *key)
{
    int index = 0;
    Entry_t *current = NULL;
    int hash_f = 0;

    if (!ht || !key || my_strlen(key) == 0)
        return NULL;
    hash_f = hash(key, ht->size);
    index = hash_f % ht->size;
    current = ht->table[index];
    while (current != NULL) {
        if (my_strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}

void ht_dump(hashtable_t *ht)
{
    Entry_t *entry = NULL;

    if (!ht)
        return;
    for (int i = 0; i < ht->size; i++) {
        entry = ht->table[i];
        write(1, "[", my_strlen("["));
        my_put_nbr(i);
        write(1, "]:\n", my_strlen("]:\n"));
        while (entry != NULL) {
            write(1, "> ", my_strlen("> "));
            my_put_nbr(ht->hash(entry->key, ht->size));
            write(1, " - ", my_strlen(" - "));
            write(1, entry->value, my_strlen(entry->value));
            write(1, "\n", my_strlen("\n"));
            entry = entry->next;
        }
    }
}
