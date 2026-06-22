/*
** EPITECH PROJECT, 2024
** dfghj
** File description:
** my.h
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

#ifndef __MY_H__
    #define __MY_H__
    #define RW sfRenderWindow
    #define SVF sfVector2f

typedef struct passinga_s {
    sfVector2f i;
    sfVector2f f;
    float v;
    float dur;
    struct passinga_s *next;
} passinga_t;

typedef struct passingt_s {
    sfVector2f tour;
    float r;
    struct passingt_s *next;
} passingt_t;

char *insert(char **tab, int i);
int retour(char **tab);
void open_window(sfRenderWindow *window, sfEvent event);
void move_avion(passinga_t *av, float time_elsp);
int display_window(sfRenderWindow *window, sfEvent event, char **argv);
int to_number(char *str);
int my_strncmp(char const *s1, char const *s2, int n);
passinga_t **pass_a(char **tab, passinga_t **a);
passingt_t **pass_t(char **tab, passingt_t **b);
int stsize(int argc, char **argv);
char *error_case_one(int fd, char *buffer);
char *error_case_two(int nb_read, int fd, char *buffer);
char *error_case_three(int nb_column, int nb_line, char **tab);
char **my_str_to_word_array(char *str);
char *file(char const *filepath);
int count_separator(char *str, char c, char d);
int nb_char(char *str, char c, char d);
void my_putchar(char c);
int my_putstr(char const *str);
int main(int argc, char **argv, sfTexture *texture, sfSprite *sprite);
void move_avion(passinga_t *av, float time_elsp);

#endif
