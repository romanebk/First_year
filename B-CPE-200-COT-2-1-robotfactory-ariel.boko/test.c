/*
** EPITECH PROJECT, 2025
** big endian
** File description:
** big endian
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "op.h"
#include <stdint.h>

int swap(int value)
{
    int leftmost_byte = 0;
    int left_middle_byle = 0;
    int right_middle_byte = 0;
    int rightmost_byte = 0;
    int result = 0;

    leftmost_byte = (value & 0x000000FF) >> 0;
    left_middle_byle = (value & 0x0000FF00) >> 8;
    right_middle_byte = (value & 0x00FF0000) >> 16;
    rightmost_byte = (value & 0xFF000000) >> 24;
    leftmost_byte <<= 24;
    left_middle_byle <<= 16;
    right_middle_byte <<= 8;
    rightmost_byte <<= 0;
    result = (leftmost_byte | left_middle_byle
        | right_middle_byte | rightmost_byte);
    return result;
}
