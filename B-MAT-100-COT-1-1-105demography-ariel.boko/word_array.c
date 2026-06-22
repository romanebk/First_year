/*
** EPITECH PROJECT, 2024
** dfghjk
** File description:
** hgfd
*/

//#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int count_separator(char *str, char c, char d)
{
    int a = 0;
    int b = 0;

    while (str[a] != '\0') {
        if (str[a] == c || str[a] == d) {
            b++;
        }
        a++;
    }
    return b;
}

int nb_char(char *str, char c, char d)
{
    int count = 0;

    while (str[count] != '\0' && str[count] != c && str[count] != d) {
        count++;
    }
    return count;
}

char *insert(char **tab, int i)
{
    for (int j = 0; j < i; j++)
	free(tab[j]);
    free(tab);
    return NULL;
}

char *error_case_three(int nb_column, int nb_line, char **tab)
{
    if (tab == NULL)
        return NULL;
    for (int i = 0; i < nb_line; i++) {
        tab[i] = malloc(sizeof(char) * (nb_column + 1));
        if (tab[i] == NULL) {
            insert(tab, i);
        }
    }
}

char **my_str_to_word_array(char *str)
{
    int a = 0;
    int b = 0;
    int nb_line = count_separator(str, ';', '\n') + 1;
    int nb_column = nb_char(str, ';', '\n') + 1;
    char **tab = malloc(sizeof(char *) * (nb_line + 1));

    error_case_three(nb_column, nb_line, tab);
    for (int i = 0; str[i] != '\0'; i++) {
      if (str[i] == ';' || str[i] == '\n') {
            tab[a][b] = '\0';
            a++;
            b = 0;
        } else {
            tab[a][b] = str[i];
            b++;
        }
    }
    tab[a + 1] = NULL;
    return tab;
}
/*
int main(int argc, char *argv[])
{
    char *content = file(argv[1]);
    char **words = my_str_to_word_array(content);

    if (content == NULL) {
        return 84;
    }
    if (words == NULL) {
        free(content);
        return 84;
    }
    for (int i = 0; words[i] != NULL; i++) {
        puts(words[i]);
        free(words[i]);
    }
    free(words);
    free(content);
    return 0;
}
*/
