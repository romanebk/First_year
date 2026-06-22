/*
** EPITECH PROJECT, 2024
** dfghjk
** File description:
** main
*/

#include "my.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Clock.h>
#include <SFML/System.h>
#include <time.h>
#include <SFML/Window.h>

int usage(int argc, char **argv)
{
    if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
        my_putstr("Air traffic simulation panel\n");
        my_putstr("USAGE\n");
        my_putstr(" ./my_radar [OPTIONS] path_to_script\n");
        my_putstr(" path_to_script The path to the script file.\n");
        my_putstr("OPTIONS\n");
        my_putstr(" -h           print the usage and quit.\n");
        my_putstr("USER INTERACTIONS\n");
        my_putstr(" `L'       key enable/disable hitboxes and areas.\n");
        my_putstr(" `S'       key enable/disable sprites\n");
    } else {
        return 84;
    }
}

int main(int argc, char **argv, sfTexture *texture, sfSprite *sprite)
{
    sfRenderWindow *win;
    sfVideoMode vid = {1920, 1080, 32};
    sfEvent event;

    win = sfRenderWindow_create(vid, "SFML window", sfClose | sfResize, NULL);
    if (argc != 2) {
        return 84;
    } else if (argc == 2 && argv[1][0] == '-' &&
        argv[1][1] == 'h' && argv[1][2] == '\0') {
        usage(argc, argv);
    } else {
        display_window(win, event, argv);
    }
    return 0;
}
