/*
** EPITECH PROJECT, 2024
** fghjk
** File description:
** fghjkl
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include <curses.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <fcntl.h>

#ifndef _MY_H_
    #define _MY_H_

typedef struct time {
    int day;
    int hour;
    int min;
    int sec;
} temp_t;

typedef struct task_s {
    int run;
    int sleep;
    int stop;
    int zomb;
} task_t;

int line_task(void);
int color_line(void);
char *error_case_one(int fd, char *buffer);
char *error_case_two(int nb_read, int fd, char *buffer);
void display_cpu(void);
double *getcpu(void);
double *result(void);
int check(char *str);
void run_sleep_zombie(char *path);
void usage2(void);
void usage3(void);
char *info(char *str);
void calcul_swap(void);
void calcul_mem(void);
char **my_str_to_word_array(char *str);
char *file(char const *filepath);
int main(int argc, char **argv);
int getload(double *loadavg, int nb_el);
int *getuptime(double *uptime, int nb_el);
int heure(void);
int usage(int argc, char **argv);

#endif
