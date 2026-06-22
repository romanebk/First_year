/*
** EPITECH PROJECT, 2024
** hgfdez
** File description:
** gfds
*/

#include "my.h"

int color_line(void)
{
    raw();
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    attron(COLOR_PAIR(1));
    mvprintw(6, 0, "    PID USER      PR NI    VIRT    RES    SHR S"
        "  %%CPU  %%MEM     TIME+ COMMAND");
    attroff(COLOR_PAIR(1));
    return 0;
}

void convert(void)
{
    int d = 0;
    int h = 0;
    int m = 0;
    double uptime[1] = {0};
    int up = 0.0;

    getuptime(uptime, 1);
    up = uptime[0];
    d = up / 86400;
    h = (up % 86400) / 3600;
    m = ((up % 86400) % 3600) / 60;
    if (m < 10) {
        printw(" up %d day, %d:0%d,  0 user,  ", d, h, m);
    } else if (m >= 10) {
        printw(" up %d day, %d:%d,  0 user,  ", d, h, m);
    }
}

void display(void)
{
    double avg[3] = {0};

    convert();
    getload(avg, 3);
    printw("load average: %.2f, %.2f, %.2f\n", avg[0], avg[1], avg[2]);
    line_task();
    display_cpu();
    calcul_mem();
    calcul_swap();
    color_line();
}

void boucle(void)
{
    double avg[3] = {0};
    double uptime[1] = {0};
    int c = 0;

    while (1) {
        clear();
        heure();
        display();
        refresh();
        c = getch();
        if (c == 'q')
            break;
        usleep(1000 * 500);
    }
}

int main(int argc, char **argv)
{
    if (argc == 2) {
        if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0')
            usage(argc, argv);
    } else {
        initscr();
        curs_set(0);
        timeout(3000);
        noecho();
        curs_set(FALSE);
        nodelay(stdscr, TRUE);
        boucle();
        endwin();
        return 0;
    }
}
