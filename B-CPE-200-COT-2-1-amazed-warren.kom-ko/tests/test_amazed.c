/*                                                                                                                                     
** EPITECH PROJECT, 2025                                                                                                               
** 105 demography                                                                                                                      
** File description:                                                                                                                   
** unit test                                                                                                                           
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

int my_strlen(char const *str);
Test(my_strlen, count_carac)
{
    int a = my_strlen("hello");
    int b = strlen("hello");
    cr_assert_eq(a, b);
}
