/*
** EPITECH PROJECT, 2025
** pipeto
** File description:
** units tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/pipeto.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_getnbr, gets_number_from_string)
{
    int nbr = my_getnbr("1234ab567");
    cr_expect(nbr == 1234);
}

Test(my_strlen, returns_string_length)
{
    int nb = my_strlen("test");
    cr_expect(nb == 4);
}

/*
Test(help1, help1_test, .init = redirect_all_std)
{
    char *r = hash("admin123");
    cr_assert_eq(r, "Y]gdj.02");
}
*/
