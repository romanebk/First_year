/*
** EPITECH PROJECT, 2025
** move
** File description:
** move
*/

#include "op.h"

unsigned int move(unsigned int ma)
{
    return ((ma >> 24) & 0xFF) |
        ((ma >> 8) & 0xFF00) |
        ((ma << 8) & 0xFF0000) |
        ((ma << 24) & 0x00);
}
