/*
** EPITECH PROJECT, 2025
** STUMPER 2
** File description:
** hidenp
*/

#include "my.h"

static bool can_be_found(char *haystack, char *ne)
{
    int count1[26] = {0};
    int count2[26] = {0};

    for (int i = 0; haystack[i] != '\0'; i++)
        count1[haystack[i] - 'a']++;
    for (int i = 0; ne[i] != '\0'; i++)
        count2[ne[i] - 'a']++;
    for (int i = 0; ne[i] != '\0'; i++) {
        if (count1[ne[i] - 'a'] < count2[ne[i] - 'a'])
            return false;
    }
    return true;
}

bool is_in_order(char *haystack, char *needle)
{
    int mark[my_strlen(needle)];
    int a = 0;
    int last = 0;

    for (int i = 0; haystack[i] != '\0'; i++) {
        for (int j = last; needle[j] != '\0'; j++)
            if (haystack[i] == needle[j]) {
                mark[a] = i;
                a++;
                last = j;
                break;
            }
    }
    for (int i = 0; i < my_strlen(needle); i++) {
        if (!(i != my_strlen(needle) && mark[i] < mark[i + 1]))
            return false;
    }
    return true;
}

bool is_in_grid(char *haystack, char *needle)
{
    if (can_be_found(haystack, needle)
        && is_in_order(haystack, needle))
        return true;
    return false;
}

char highlight(char one, char two, char found)
{
    if (one == two)
        return to_upper(found);
    return found;
}

void grid_solver(char **tab, char *haystack, char *needle, int def)
{
    int last = 0;
    int row = 0;
    int col = 0;

    for (int i = 0; haystack[i]; i++) {
        for (int j = last; needle[j]; j++) { 
            row = i / def;
            col = i % def;
            tab[row][col] = highlight(haystack[i], needle[j], tab[row][col]);
        }
    }
    print_grid(tab, def);
    exit(0);
}
