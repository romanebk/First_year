/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** bibliothèque
*/

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Clock.h>
#include <SFML/System.h>
#include <time.h>
#include <SFML/Window.h>
#include <math.h>

#ifndef _MY_H_
    #define _MY_H_
    #define RW sfRenderWindow
    #define SVF sfVector2f
    #define MAP_X 12
    #define MAP_Y 12

typedef struct strc {
    sfRenderWindow *window;
    sfUint32 style;
    sfVector2f scale;
    sfVideoMode mode;
    sfEvent event;
    sfSprite *spe;
    sfRectangleShape *rec;
    sfVector2f pos;
    sfVertexArray *arr;
    sfVector2f size;
    int i;
    int z;
    sfVector2f iso;
    sfVector2f **tab;
} stc_t;

typedef struct stcr {
    sfTexture *texture1;
    sfView *view;
    float rot;
    float zoom;
    sfBool rota;
    sfRenderStates states;
} st_t;

st_t my_st(void);
stc_t my_struct(void);
void cut_create(stc_t st);
void cut_func(stc_t *st, int i, int j, st_t *s);
void cut_rot(st_t *s, stc_t *st);
void cut_zoom(st_t *s, stc_t *st);

//void cut_rot(sfRenderWindow *window, sfEvent event, st_t *s);
//void cut_zoom(sfRenderWindow *window, sfEvent event, st_t *s);
//void rotation(stc_t *var, float angle);
sfVector2f project_iso_point(int x, int y, int z);
sfVector2f **create_2d_map(int **map);
sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2);
int animate(sfIntRect *area, int offset, int max_value);
int func(stc_t *st, st_t *s);
void zoom(stc_t *st, st_t *s, float del);
void rotation(st_t *s, float angle, stc_t *st);
//void rotation(st_t *s, float angle, stc_t *st);
void my_putchar(char c);
sfVertexArray *create_qd(sfVector2f point[4], sfTexture *texture);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int mini_printf(const char *format, ...);
double convert(double a);
void free_function(sfVector2f **tab);
sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2);
void analyse_events(stc_t *st, st_t *s);
//void analyse_events(sfRenderWindow *window, sfEvent event, st_t *s);
void create(void);
int main(int ac, char **av);
int usage(int ac, char **av);

#endif
