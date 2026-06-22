/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include "../include/my.h"

int main(int argc, char **argv)
{
    int n = 0;
    double k = 0;
    int i0 = 0;
    int i1 = 0;

    if (argc < 2 || argc > 4)
        exit(84);
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        usage(argc, argv);
        return 0;
    }
    n = atoi(argv[1]);
    if (n < 0)
        return 84;
    if (argc == 3) {
        k = atof(argv[2]);
        if (k < 1 || k > 4 || check_arg(argv[2]) || check_vir(argv[1]))
            return 84;
        calcul_population(n, k);
    } else if (argc == 4) {
        i0 = atoi(argv[2]);
        i1 = atoi(argv[3]);
        if (i0 <= 0 || i1 <= 0 || i1 < i0 || i0 < n
            || check_vir(argv[1])
            || check_vir(argv[2])
            || check_vir(argv[3]))
            return 84;
        generate_synthetic_data(n, i0, i1);
    } else
        return 84;
    return 0;
}
