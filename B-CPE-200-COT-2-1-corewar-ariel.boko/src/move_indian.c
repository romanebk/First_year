/*
** EPITECH PROJECT, 2025
** function
** File description:
** move
*/

#include "../include/my.h"

unsigned int move_indian(unsigned int ma)
{
    return ((ma >> 24) & 0xFF) |
        ((ma >> 8) & 0xFF00) |
        ((ma << 8) & 0xFF0000) |
        ((ma << 24) & 0x00);
}
