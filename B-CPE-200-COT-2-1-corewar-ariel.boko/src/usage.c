/*
** EPITECH PROJECT, 2024
** Robot
** File description:
** corewar
*/

#include "../include/my.h"

int usage(int ac, char **av)
{
    mini_printf("USAGE\n");
    mini_printf("./corewar [-dump nbr_cycle] [[-n prog");
    mini_printf("_number] [-a load_address] prog_name] ...\n");
    mini_printf("DESCRIPTION\n");
    mini_printf("dump nbr_cycle dumps the memory after the ");
    mini_printf("nbr_cycle execution (if the round isn't\n");
    mini_printf("already over) with the following format: 32");
    mini_printf(" bytes/line in hexadecimal (A0BCDEFE1DD3...)");
    mini_printf("-n prog_number sets the next program's number.");
    mini_printf("By default, the first free number in ");
    mini_printf("the parameter order\n");
    mini_printf("-a load_address sets the next program's loading");
    mini_printf(" address. When no address is specified, optimize ");
    mini_printf("the addresses so that the processes are as far ");
    mini_printf("away from each other as possible. ");
    mini_printf("The addresses are MEM_SIZE modulo.\n");
    return 0;
}
