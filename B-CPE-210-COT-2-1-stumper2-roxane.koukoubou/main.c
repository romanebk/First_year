/*
** EPITECH PROJECT, 2025
** STUMPER 2
** File description:
** boogle
*/

#include "my.h"

static int launch_loop(char *str, int def)
{
    char **tab = create_grid(str, def);
    char *ptr = NULL;
    size_t size = 0;

    if (!tab)
        return 84;
    print_grid(tab, def);
    while (1) {
        printf("> ");
        if (getline(&ptr, &size, stdin) == -1)
            return 0;
        ptr[strlen(ptr) - 1] = '\0';
        if (my_str_islower(ptr) == -1)
            return 84;
        if (is_in_grid(str, ptr))
            grid_solver(tab, str, ptr, def);
        else
            printf("The word \"%s\" is not in the grid.\n", ptr);
    }
    return 0;
}

void check_arg(char *a1, char* a2, char *a3)
{
    if (!a1) {
        my_putstr("boogle: Grid code undefined\n", 2);
    }
    if ((a1 && my_str_islower(a1) == -1)) {
        my_putstr("boogle: Invalid argument\n", 2);
        exit(84);
    }
    if (a3 && str_isnumber(a3) == -1) {
        my_putstr("boogle: Invalid argument\n", 2);
        exit(84);
    }
    return;
}

int execute_basic(int ac, char **av)
{
    char *a1 = NULL;
    char *a2 = NULL;
    char *a3 = NULL;
    int g = 0;
    int s = 0;

    for (int i = 1; av[i]; i++) {
        if (strcmp(av[i], "-g") == 0)
            g = i;
        if (strcmp(av[i], "-s") == 0)
            s = i;
    }
    if (s && g)
        check_arg(av[g + 1], NULL, av[s + 1]);
    return 0;
}

int main(int ac, char **av)
{
    if (ac < 3 || ac > 7) {
        my_putstr("boogle: Incorrect number of arguments\n", 2);
        return 84;
    }
    if (ac == 3 && strcmp(av[1], "-g") == 0)
        launch_loop(av[2], 4);
    else if (ac > 4 && strcmp(av[3], "-s") == 0) {
        execute_basic(ac, av);
        launch_loop(av[2], atoi(av[4]));
    } else {
        my_putstr("boogle: Incorrect number of arguments\n", 2);
        return 84;
    }
    return 0;
}
