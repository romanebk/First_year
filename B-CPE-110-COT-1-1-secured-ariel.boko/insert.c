/*
** EPITECH PROJECT, 2025
** function
** File description:
** insertion
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

int cut_insert(hashtable_t *ht, char *key, char *value)
{
    int retour = 0;
    int hash_f = 0;
    int index = 0;
    Entry_t *entry = NULL;

    hash_f = ht->hash(key, ht->size);
    index = hash_f % ht->size;
    entry = ht->table[index];
    for (; entry != NULL; entry = entry->next) {
        if (my_strcmp(entry->key, key) == 0) {
            free(entry->value);
            entry->value = my_strdup(value);
            retour = 2;
            return retour;
        }
    }
    return 0;
}

int insert_elem(hashtable_t *ht, Entry_t *entry, char *key, char *value)
{
    entry->key = my_strdup(key);
    entry->value = my_strdup(value);
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int index = 0;
    Entry_t *entry = NULL;
    int hash_f = 0;

    if (!ht || !key || !value || my_strlen(key) == 0 || my_strlen(value) == 0)
        return 84;
    hash_f = hash(key, ht->size);
    index = hash_f % ht->size;
    if (cut_insert(ht, key, value) == 2)
        return 0;
    entry = malloc(sizeof(Entry_t));
    if (!entry)
        return 84;
    insert_elem(ht, entry, key, value);
    entry->next = ht->table[index];
    ht->table[index] = entry;
    return 0;
}
