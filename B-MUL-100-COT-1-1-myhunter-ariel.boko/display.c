/*
** EPITECH PROJECT, 2024
** fghkl
** File description:
** gfds
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

void display_window(sfRenderWindow *window, sfEvent event)
{
    sfSprite *sprite_one = sfSprite_create();
    sfTexture *texture_one = sfTexture_createFromFile("Download Summer Deep Forest Landscape in Cartoon Style for free(1).jpeg", NULL);
    sfVector2f size_one = {2.7, 2.7};
    sfSprite *sprite_two = sfSprite_create();
    sfTexture *texture_two = sfTexture_createFromFile("img1.png", NULL);
    sfVector2f size_two = {700, 300};

    sfSprite_setScale(sprite_one, size_one);
    sfSprite_setTexture(sprite_one, texture_one, sfFalse);
    sfSprite_setTexture(sprite_two, texture_two, sfFalse);
    sfSprite_setPosition(sprite_two, size_two);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
    }
    sfRenderWindow_drawSprite(window, sprite_one, NULL);
    sfRenderWindow_drawSprite(window, sprite_two, NULL);
    sfRenderWindow_display(window);
    click_start(window, event);
}
