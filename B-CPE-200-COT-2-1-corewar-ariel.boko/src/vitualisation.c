/*
** EPITECH PROJECT, 2025
** voir
** File description:
** voir
*/

#include "../include/op.h"
#include "../include/my.h"

void init_display(void)
{
    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
}

void displayhead(vm_t *vm)
{
    printw("\t\t\t\t\t\t\t\t\t\t\tCOREWAR\n");
    for (int i = 0; i < vm->nb_players; i++) {
        attron(COLOR_PAIR(i + 1));
        printw("Joueur %d: %s\n", vm->champions[i].number, vm->champions[i].name);
        attroff(COLOR_PAIR(i + 1));
    }
    printw("\nCicle to die: %d / %d\n", vm->cycle, vm->cycle_to_die);
    printw("Live count: %d / 40\n", vm->live_count);
    printw("Total Cycle: %d\n\n\n", vm->cycle);
}

static int know_colors(vm_t *vm, int color, int i)
{
    for (int j = 0; j < vm->nb_players; j++) {
        if (i >= vm->champions[j].load_address && 
            i < vm->champions[j].load_address + vm->champions[j].size) {
            color = j + 1;
            break;
        }
    }
    return color;
}

void display_memory(vm_t *vm)
{
    int color;

    clear();
    displayhead(vm);
    for (int i = 0; i < MEM_SIZE; i++) {
        color = 0;
        color = know_colors(vm, color, i);
        if (color > 0) {
            attron(COLOR_PAIR(color));
            printw( "%02x", (unsigned char)vm->memory[i]);
            attroff(COLOR_PAIR(color));
        } else {
            printw("%02x", (unsigned char)vm->memory[i]);
        }
    }
    refresh();
}

void victory(int last_live_player, vm_t *vm)
{
    if (last_live_player == 1 ) {
        mini_printf("Le joueur %d (%s) a gagné!\n",
                vm->champions[last_live_player-1].number,
                vm->champions[last_live_player-1].name);
    } else if (last_live_player == 0 && vm->nb_players == 0) {
        mini_printf("Aucun vainqueur!\n");
    } else {
        for (int i = 0; i < vm->nb_players; i++) {
            mini_printf("Le joueur %d (%s) est en vie\n",
            vm->champions[i].number,
            vm->champions[i].name);
        }
    }
}

int run_vm(vm_t *vm)
{
    int key;
    int last_live_player = 0;

    process_t *initial_process = malloc(sizeof(process_t));
    timeout(100);
    while (vm->cycle_to_die > 0) {
        display_memory(vm);
        key = getch();
        if (key == 'q' || key == 'Q')
            break;
        if (key != ERR && key != 'q' && key != 'Q');
        vm->cycle++;
        if (vm->live_count > 0) {
            last_live_player = vm->nb_players;
            victory(last_live_player, vm);
        }

    }
    clear();
    return 0;
}
