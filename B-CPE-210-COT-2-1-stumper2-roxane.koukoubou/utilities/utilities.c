/*
** EPITECH PROJECT, 2025
** Robot Factory
** File description:
** Additional helper functions.
*/

#include "../my.h"

int my_strlen(char *str)
{
    int a = 0;

    if (str == NULL)
        return 0;
    while (str[a] != '\0')
        a++;
    return a;
}

int my_putstr(char *str, int fd)
{
    for (int i = 0; str[i]; i++)
        write(fd, &str[i], 1);
    return 0;
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;
    int j = 0;

    while (s1[i] != '\0' || s2[j] != '\0') {
        if (s1[i] != s2[j]) {
            return (s2[j] - s1[i]);
        }
        i++;
        j++;
    }
    return 0;
}

int my_strncmp(char *s1, char *s2, int n)
{
    int a = 0;

    while (a < n && s1[a] && s2[a]) {
        if (s1[a] != s2[a]) {
            return (s1[a] - s2[a]);
        }
        a++;
    }
    return 0;
}

int my_getnbr(char *str)
{
    int a = 0;
    int i = 1;
    int j = 0;

    while (str[a] == '-' || str[a] == '+') {
        if (str[a] == '-')
            i = i * (-1);
        a++;
    }
    for (; str[a] >= '0' && str[a] <= '9'; a++) {
        j = j * 10 + (str[a] - 48);
    }
    return (i * j);
}
