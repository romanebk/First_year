/*
** EPITECH PROJECT, 2025
** rvf"'
** File description:
** "f'df"
*/

#ifndef HASHTABLE_H
  #define HASHTABLE_H

typedef struct enter {
    char *key;
    char *value;
    struct enter *next;
} Entry_t;

typedef struct hashtable_s {
    int size;
    Entry_t **table;
    int (*hash)(char *, int);
} hashtable_t;

int my_str(char const *str);
void my_char(char c);
int my_put_nbr(int nb);
int hash(char *key, int len);
int cut_insert(hashtable_t *ht, char *key, char *value);
int insert_elem(hashtable_t *ht, Entry_t *entry, char *key, char *value);
char *my_strdup(char *str);
int my_strcmp(char *s1, char *s2);
char last_char(char *str);
int my_strlen(char *str);
void complet(hashtable_t *ht, Entry_t *prev, Entry_t *current, int index);
void complete(Entry_t *current, Entry_t *temp);
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *table);
int ht_insert(hashtable_t *ht, char *key, char *value);
void ht_dump(hashtable_t *ht);
char *ht_search(hashtable_t *ht, char *key);
int ht_delete(hashtable_t *ht, char *key);

#endif
