/*
** EPITECH PROJECT, 2024
** dfghjk
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

int usage(int argc, char **argv)
{
    if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
        my_putchar('\n');
        my_putstr("USAGE");
        my_putchar('\n');
        my_putstr("./my_hunter");
        my_putchar('\n');
        my_putchar('\n');
        my_putchar('\n');
        my_putstr("DESCRIPTION");
        my_putchar('\n');
        my_putstr("The game is Duck Hunt");
        my_putchar('\n');
        my_putstr("The player is a hubter who shoots ducks");
        my_putchar('\n');
        my_putstr("The player can click on them and shoot them");
	my_putchar('\n');
    }
    else {
        return 84;
    }
}

int main(int argc, char **argv)
{
    sfRenderWindow *windows;
    sfVideoMode video_mode = {1920, 1080, 32};
    sfEvent event;
    sfMusic *music = sfMusic_createFromFile("lady-of-the-80x27s-128379.mp3");
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    windows = sfRenderWindow_create(video_mode, "SFML window", sfClose | sfResize, NULL);
    if (argc == 2) {
	usage(argc, argv);
    }
    else {
	while (sfRenderWindow_isOpen(windows)) {
	    display_window(windows, event);
	}
    }
}
