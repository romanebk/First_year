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

Test(check_arg4, check_arg_test, .init = redirect_all_std)
{
    int r = check_arg("-19");
    r = check_arg("19");
    cr_assert_eq(r, 0);
}

Test(check_input1, check_input1_test, .init = redirect_all_std)
{
    int ac = 2;
    char *av[2] = {" ", "COs"};
    int r = check_input(ac, av);
    cr_assert_eq(r, 84);
}

Test(check_input2, check_input2_test, .init = redirect_all_std)
{
    int ac = 2;
    char *av[2] = {" ", "COS"};
    int r = check_input(ac, av);
    cr_assert_eq(r, 0);
}

Test(valid_coe, valid_coe_test, .init = redirect_all_std)
{
    int r = valid_coe(6);
    int r1 = valid_coe(10);
    cr_assert_eq(r, 0);
    cr_assert_eq(r1, 84);
}
