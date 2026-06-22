/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** function
*/

#include "my.h"

const int map[MAP_Y][MAP_Y] = {
    {00, 00, 00, 00, 00, 00},
    {00, 00, 00, 00, 00, 00},
    {00, 00, 00, 07, 03, 00},
    {00, 00, 00, 00, 00, 00},
    {00, 00, 00, 00, 00, 00},
    {10, 00, 00, 00, 00, 00},
};

st_t my_st(void)
{
    st_t s;

    s.texture1 = sfTexture_createFromFile("image.jpg", NULL);
    s.view = sfView_create();
    s.rot = 0.0f;
    s.zoom = 1.0f;
    s.rota = sfFalse;
    s.states = (sfRenderStates){
        .texture = s.texture1,
        .shader = NULL,
        .transform = sfTransform_Identity,
        .blendMode = sfBlendAlpha,
    };
    return s;
}

stc_t my_struct(void)
{
    stc_t st;

    st.window;
    st.style = (sfUint32){sfResize | sfClose};
    st.scale = (sfVector2f){3.5, 2.5};
    st.mode = (sfVideoMode){1920, 1080, 32};
    st.event;
    st.spe = sfSprite_create();
    st.rec = sfRectangleShape_create();
    st.pos;
    st.arr;
    st.size = (sfVector2f){2, 2};
    st.i = 0;
    st.z = 0;
    st.iso;
    st.tab = malloc(sizeof(sfVector2f) * MAP_Y);
    return st;
}

void cut_func(stc_t *st, int i, int j, st_t *s)
{
    if (j < MAP_X - 1){
        st->arr = create_line(&st->tab[i][j], &st->tab[i][j + 1]);
        sfRenderWindow_drawVertexArray(st->window, st->arr, &s->states);
    }
    if (i < MAP_Y - 1){
        st->arr = create_line(&st->tab[i][j], &st->tab[i + 1][j]);
        sfRenderWindow_drawVertexArray(st->window, st->arr, &s->states);
    }
}

int func(stc_t *st, st_t *s)
{
    sfVector2f point[4];
    sfRenderStates states = s->states;

    for (int i = 0; i < MAP_Y - 1; i++) {
        for (int j = 0; j < MAP_X - 1; j++) {
            point[0] = st->tab[i][j];
            point[1] = st->tab[i][j + 1];
            point[2] = st->tab[i + 1][j + 1];
            point[3] = st->tab[i + 1][j];
            st->arr = create_qd(point, s->texture1);
            sfRenderWindow_drawVertexArray(st->window, st->arr, &states);
            cut_func(st, i, j, s);
            sfRectangleShape_setOutlineColor(st->rec, sfBlue);
        }
    }
    sfRenderWindow_display(st->window);
}

void cut_create(stc_t st)
{
    for (; st.z < MAP_Y; st.z++) {
        st.tab[st.z] = malloc(sizeof(sfVector2f) * MAP_X);
        for (int j = 0; j < MAP_X; j++)
            st.tab[st.z][j] = project_iso_point((j * 50) + 500,
            (st.z * 50) - 100, map[st.z][j] * 50);
    }
    st.tab[st.z] = NULL;
}
