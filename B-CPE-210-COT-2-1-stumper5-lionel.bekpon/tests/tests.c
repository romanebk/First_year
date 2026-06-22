/*
** EPITECH PROJECT, 2025
** tests
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include "../include/my.h"

int my_strlen(char const *str);
Test(my_strlen, count_carac)
{
    int a = my_strlen("hello");
    int b = strlen("hello");
    cr_assert_eq(a, b);
}

int count_occur(char *str, char c);
Test(count_occur, count_occur_charac)
{
    int a = count_occur("bbonjour", 'b');
    int b = count_occur("hello", 'l');
    cr_assert_eq(a, b);
}

int find_char(char *str, char c);
Test(find_char, find_char_str)
{
    int a = find_char("bonjour", 'b');
    int b = find_char("helo", 'l');
    cr_assert_eq(a, b);
}
