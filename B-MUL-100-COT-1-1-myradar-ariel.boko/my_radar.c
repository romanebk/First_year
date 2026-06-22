/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** my_radar
*/

#include <stddef.h>
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

void open_window(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

void move_avion(passinga_t *av, float time_elsp)
{
    float n_pixel = av->v * time_elsp;

    if (av->i.x <= av->f.x) {
        av->i.x = av->i.x + n_pixel;
    } else {
        av->i.x = av->i.x - n_pixel;
    }
    if (av->i.y <= av->f.y) {
        av->i.y = av->i.y + n_pixel;
    } else {
        av->i.y = av->i.y - n_pixel;
    }
}

int recup(char *contain, char **tab, char **argv)
{
    contain = file(argv[1]);
    if (contain == NULL) {
        return 84;
    }
    tab = my_str_to_word_array(contain);
    if (tab == NULL) {
        free(contain);
        return 84;
    }
}

void destroy(sfSprite *sprite, sfTexture *texture, sfRenderWindow *window)
{
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
}

int display_window(sfRenderWindow *window, sfEvent event, char **argv)
{
    char *contain;
    char **tab;
    passinga_t **a = NULL;
    passingt_t *t = NULL;
    sfTexture *texture = sfTexture_createFromFile("Screenshot from 2025-01-06 09-43-50.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f size = {4.9, 4};
    sfTexture *texture_a = sfTexture_createFromFile("plane.png", NULL);
    sfTexture *texture_t = sfTexture_createFromFile("tower.png", NULL);

    recup(contain, tab, argv);
    sfSprite_setScale(sprite, size);
    sfSprite_setTexture(sprite, texture, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
    open_window(window, event);
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);
    }
    destroy(sprite, texture, window);
}
