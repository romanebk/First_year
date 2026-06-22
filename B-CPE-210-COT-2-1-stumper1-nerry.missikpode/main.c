/*
** EPITECH PROJECT, 2025
** function
** File description:
** main
*/

#include "my.h"


int main(int argc, char **argv)
{
    int n = 0;

    if (argc == 4 && my_strcmp(argv[1], "-n") == 0) {
        n = to_number(argv[2]);
        tail_function_n(argv, n);
        return 0;
    }
    tail_function(argv);
    return 0;
}
