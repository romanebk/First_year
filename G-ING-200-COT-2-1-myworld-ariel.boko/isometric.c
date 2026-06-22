/*
** EPITECH PROJECT, 2025
** turn to 3D in 2D
** File description:
** function
*/

#include "my.h"

double convert(double a)
{
    double res = 0;

    res = (a * M_PI) / 180;
    return res;
}

sfVector2f project_iso_point(int x, int y, int z)
{
    sfVector2f point = {0.0, 0.0};

    point.x = cos(convert(45)) * x - cos(convert(45)) * y;
    point.y = sin(convert(35)) * y + sin(convert(35)) * x - z;
    return point;
}

sfVertexArray *create_qd(sfVector2f point[4], sfTexture *texture)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVector2u size = sfTexture_getSize(texture);
    sfVertex vertex2[4] = {
        {.position = point[0], .texCoords = (sfVector2f){0, 0}},
        {.position = point[1], .texCoords = (sfVector2f){size.x, 0}},
        {.position = point[2], .texCoords = (sfVector2f){size.x, size.y}},
        {.position = point[3], .texCoords = (sfVector2f){0, size.y}},
    };

    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    for (int a = 0; a < 4; a++) {
        vertex2[a].color = sfWhite;
        sfVertexArray_append(vertex_array, vertex2[a]);
    }
    return (vertex_array);
}
