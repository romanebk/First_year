/*
** EPITECH PROJECT, 2024
** sdfghjk
** File description:
** jhgfdx
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
#include "my.h"

void window_two(sfRenderWindow *window, sfEvent event)
{
    sfSprite *sprite_one = sfSprite_create();
    sfTexture *texture_one = sfTexture_createFromFile("Download Summer Deep Forest Landscape in Cartoon Style for free(1).jpeg", NULL);
    sfVector2f size_one = {2.7, 2.7};
    sfSprite *sprite_two = sfSprite_create();
    sfTexture *texture_two = sfTexture_createFromFile("B-MUL-100_Bootstrap_my_hunter_spritesheet.png", NULL);
    sfVector2f size_two = {0.4, 0.4};
    sfIntRect rect = {0, 0, 110, 110};
    sfClock * clock;
    sfTime time;
    float seconds;

    clock = sfClock_create();
    sfSprite_setScale(sprite_one, size_one);
    sfSprite_setTexture(sprite_one, texture_one, sfTrue);
    sfSprite_setTexture(sprite_two, texture_two, sfTrue);
    sfSprite_setPosition(sprite_two, size_two);
    while (sfRenderWindow_isOpen(window)) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        move_rect(&rect, 110, 330);
        sfClock_restart(clock);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
            //          dead_bird(window, sprite_two, event, &size_two);
        }
        move_rect(&rect, 110, 330);
        shift_bird(&size_two, seconds, 500.00, 1920);
        sfRenderWindow_drawSprite(window, sprite_one, NULL);
        sfSprite_setPosition(sprite_two, size_two);
        sfSprite_setTextureRect(sprite_two, rect);
        sfRenderWindow_drawSprite(window, sprite_two, NULL);
        sfRenderWindow_display(window);
    }
}

void shift_bird(sfVector2f *taille01, float time, float speed, float width)
{
    float x = speed * time;
    taille01->x += x;
    if (taille01->x >= width) {
        taille01->x = 0;
    }
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left >= max_value) {
        rect->left = 0;
    }
}
