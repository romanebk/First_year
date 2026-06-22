/*
** EPITECH PROJECT, 2025
** unit tests
** File description:
** unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(size_char1, size_char1_test, .init = redirect_all_std)
{
    int r = my_strlen("minishell2");
    cr_assert_eq(r, 10);
}

Test(size_char2, size_char2_test, .init = redirect_all_std)
{
    int r = my_strlen("ariel");
    cr_assert_eq(r, 5);
}

Test(size_char3, size_char3_test, .init = redirect_all_std)
{
    int r = my_strlen("");
    cr_assert_eq(r, 0);
}

Test(size_char4, size_char4_test, .init = redirect_all_std)
{
    int r = my_strlen("............");
    cr_assert_eq(r, 12);
}

Test(size_char5, size_char5_test, .init = redirect_all_std)
{
    int r = my_strlen("bonjour");
    cr_assert_eq(r, 7);
}

Test(size_char6, size_char6_test, .init = redirect_all_std)
{
    int r = my_strlen("ariel");
    cr_assert_eq(r, 5);
}

Test(size_char7, size_char7_test, .init = redirect_all_std)
{
    int r = my_strlen("ariel");
    cr_assert_eq(r, 5);
}

Test(size_char8, size_char8_test, .init = redirect_all_std)
{
    int r = my_strlen("ariel");
    cr_assert_eq(r, 5);
}

Test(my_strcmp1, my_strcmp1_test, .init = redirect_all_std)
{
    int r = my_strcmp("AB", "AB");
    cr_assert_eq(r, 0);
}

Test(my_strcmp2, my_strcmp2_test, .init = redirect_all_std)
{
    int r = my_strcmp("ABC", "AB");
    cr_assert_eq(r, 67);
}

Test(my_strcmp3, my_strcmp3_test, .init = redirect_all_std)
{
    int r = my_strcmp("ABJ", "ABC");
    cr_assert_eq(r, 7);
}

Test(my_strcmp4, my_strcmp4_test, .init = redirect_all_std)
{
    int r = my_strcmp("ABC", "ABC");
    cr_assert_eq(r, 0);
}

Test(my_strcmp5, my_strcmp5_test, .init = redirect_all_std)
{
    int r = my_strcmp("ABA", "ABZ");
    cr_assert_eq(r, -25);
}

Test(my_strcmp6, my_strcmp6_test, .init = redirect_all_std)
{
    int r = my_strcmp("Ariel", "Ariel");
    cr_assert_eq(r, 0);
}

Test(my_strcmp7, my_strcmp7_test, .init = redirect_all_std)
{
    int r = my_strcmp("", "");
    cr_assert_eq(r, 0);
}
