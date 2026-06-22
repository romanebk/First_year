/*
** EPITECH PROJECT, 2025
** 105 demography
** File description:
** unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(help1, help1_test, .init = redirect_all_std)
{
    int ac = 2;
    char *av[2] = {" ", "-h"};
    int r = usage(ac, av);
    cr_assert_eq(r, 0);
}

Test(check_arg, check_arg_test, .init = redirect_all_std)
{
    int r = check_arg("-15");
    cr_assert_eq(r, -1);
}

Test(check_arg2, check_arg_test, .init = redirect_all_std)
{
    int r = check_arg("15");
    cr_assert_eq(r, 0);
}

Test(check_arg3, check_arg_test, .init = redirect_all_std)
{
    int r = check_arg("AB");
    cr_assert_eq(r, -1);
}

Test(check_arg4, check_arg_test, .init = redirect_all_std)
{
    int r = check_arg("14");
    r = check_arg("19");
    cr_assert_eq(r, 0);
}

Test(check_arg5, check_arg_test, .init = redirect_all_std)
{
    int r = check_arg("-19l");
    r = check_arg("1m9l");
    cr_assert_eq(r, -1);
}

Test(check_arg6, check_arg_test, .init = redirect_all_std)
{
    int r = check_arg("--19");
    r = check_arg("-+19");
    cr_assert_eq(r, -1);
}

Test(check_arg7, check_arg_test, .init = redirect_all_std)
{
    int r = check_arg("!;§.");
    r = check_arg("....");
    cr_assert_eq(r, -1);
}

Test(borwein_function, borwein_function_test, .init = redirect_all_std)
{
    int r = borwein_function(10.5, 5);
    cr_assert_eq(r, 0);
}

Test(size_char, size_char_test, .init = redirect_all_std)
{
    int r = strlen("maman et papa!");
    cr_assert_eq(r, 14);
}

Test(size_char1, size_char1_test, .init = redirect_all_std)
{
    int r = strlen("maman");
    cr_assert_eq(r, 5);
}
