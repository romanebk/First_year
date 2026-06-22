/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef MY_H
    #define MY_H
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdarg.h>
    #include <stdio.h>
    #include <stdlib.h>

typedef struct ite_s {
    int i;
    int j;
    int k;
    int l;
} ite_t;

typedef struct char_s {
    char c;
    int occ;
} char_t;

typedef struct txtc_s {
    int r;
    int t;
    char *nstr;
    char *str;
    char *wanted;
    char_t **var;
} txtc_t;

int text_count(txtc_t *info);
void charge_structure(txtc_t *info);
int count_occur(char *str, char c);
int find_char(char *str, char c);
char *filtre_str(char *str);
int print_occur1(char *ptr, char *want);
int usage(int ac, char *av[]);
void tree_t(txtc_t *info);
void tree_r(txtc_t *info);
int freestruct(txtc_t *info);
#endif
