#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../my.h"

int my_strlen(char const *str);
Test(my_strlen, count_carac)
{
    int a = my_strlen("hello");
    int b = strlen("hello");
    cr_assert_eq(a, b);
}
