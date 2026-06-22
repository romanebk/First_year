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

Test(help, help_test, .init = redirect_all_std)
{
    int argc = 2;
    char *argv[2] = {" ", "-h"};
    int r = usage(argc, argv);
    cr_assert_eq(r, 0);
}

Test(check_arg, check_arg_test, .init = redirect_all_std)
{
    int r = check_arg("-15");
    cr_assert_eq(r, 0);
}

Test(check_arg2, check_arg_test, .init = redirect_all_std)
{
    int r = check_arg("15");
    cr_assert_eq(r, 0);
}

Test(check_arg3, check_arg_test, .init = redirect_all_std)
{
    int r = check_arg("AB");
    cr_assert_eq(r, 84);
}

Test(check_arg4, check_arg_test, .init = redirect_all_std)
{
    int r = check_arg("-19");
    r = check_arg("19");
    cr_assert_eq(r, 0);
}

Test(check_arg5, check_arg_test, .init = redirect_all_std)
{
    int r = check_arg("-19l");
    r = check_arg("1m9l");
    cr_assert_eq(r, 84);
}

Test(check_arg6, check_arg_test, .init = redirect_all_std)
{
    int r = check_arg("--19");
    r = check_arg("-+19");
    cr_assert_eq(r, 84);
}

Test(check_arg7, check_arg_test, .init = redirect_all_std)
{
    int r = check_arg("!;§.");
    r = check_arg("....");
    cr_assert_eq(r, 84);
}
