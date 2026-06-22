/*
** EPITECH PROJECT, 2025
** function
** File description:
** creating map
*/

#include "my.h"

void create(void)
{
    stc_t st = my_struct();
    st_t s = my_st();

    cut_create(st);
    st.window = sfRenderWindow_create(st.mode, "world", st.style, NULL);
    sfSprite_setTexture(st.spe, s.texture1, sfTrue);
    sfSprite_setScale(st.spe, st.scale);
    sfRectangleShape_setSize(st.rec, st.size);
    sfRectangleShape_setFillColor(st.rec, sfBlue);
    sfView_setCenter(s.view, (sfVector2f){960, 540});
    sfView_setSize(s.view, (sfVector2f){1920, 1080});
    sfRenderWindow_setView(st.window, s.view);
    while (sfRenderWindow_isOpen(st.window)) {
        while (sfRenderWindow_pollEvent(st.window, &st.event))
            analyse_events(&st, &s);
        sfRenderWindow_clear(st.window, sfBlack);
        func(&st, &s);
    }
}
