/*
** EPITECH PROJECT, 2024
** dfghj
** File description:
** hgfd
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Clock.h>
#include <SFML/System.h>
#include <time.h>
#include <SFML/Window.h>

#ifndef __MY_H__
    #define __MY_H__
    #define RW sfRenderWindow
    #define SVF sfVector2f
void shift_bird(sfVector2f *taille01, float time, float speed, float width);
void move_rect(sfIntRect *rect, int offset, int max_value);
void new_window(sfRenderWindow *windows, sfEvent event);
void click_start(sfRenderWindow *window, sfEvent event);
void display_window(sfRenderWindow *windows, sfEvent event);
void my_putchar(char c);
int my_putstr(char const *str);

#endif
