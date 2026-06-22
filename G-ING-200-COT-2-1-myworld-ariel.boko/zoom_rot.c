/*
** EPITECH PROJECT, 2025
** zoom and rotation
** File description:
** function that zoom and rotate the map
*/

#include "my.h"

void zoom(stc_t *st, st_t *s, float del)
{
    sfView_zoom(s->view, 1.0f + del);
    sfRenderWindow_setView(st->window, s->view);
}

void rotation(st_t *s, float angle, stc_t *st)
{
    s->rot = s->rot + angle;
    sfView_setRotation(s->view, s->rot);
    sfRenderWindow_setView(st->window, s->view);
}
