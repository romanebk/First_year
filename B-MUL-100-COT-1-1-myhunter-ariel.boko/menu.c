/*
** EPITECH PROJECT, 2024
** ghjkl
** File description:
** gfd
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

void click_start(sfRenderWindow *window, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x >= 751 || mouse.x <= 1187 && mouse.y >= 593 || mouse.y <= 681) {
        if (event.type == sfEvtMouseButtonPressed) {
            window_two(window, event);
        }
    }
}
