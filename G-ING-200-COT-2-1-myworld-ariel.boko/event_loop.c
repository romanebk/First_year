/*
** EPITECH PROJECT, 2025
** function
** File description:
** loop of event
*/

#include "my.h"

void cut_zoom(st_t *s, stc_t *st)
{
    if (st->event.key.code == sfKeyUp)
        zoom(st, s, 0.1f);
    else if (st->event.key.code == sfKeyDown)
        zoom(st, s, -0.1f);
}

void cut_rot(st_t *s, stc_t *st)
{
    if (st->event.key.code == sfKeyLeft)
        rotation(s, - 5.0f, st);
    else if (st->event.key.code == sfKeyRight)
        rotation(s, 5.0f, st);
}

void analyse_events(stc_t *st, st_t *s)
{
    if (st->event.type == sfEvtClosed)
        sfRenderWindow_close(st->window);
    if (st->event.type == sfEvtKeyPressed)
        cut_zoom(s, st);
    if (st->event.type == sfEvtKeyPressed)
        cut_rot(s, st);
}
