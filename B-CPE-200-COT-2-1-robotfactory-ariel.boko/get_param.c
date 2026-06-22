/*
** EPITECH PROJECT, 2025
** get
** File description:
** param
*/

#include "op.h"
#include "my.h"

int get_param_size(char type, int is_index)
{
    if (type == T_REG)
        return 1;
    else if (type == T_DIR)
        return 2;
    else
        return 4;
    return 0;
}
