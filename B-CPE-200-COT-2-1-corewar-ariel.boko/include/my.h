/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** My lib.
*/

#include "op.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <ncurses.h>

#ifndef MY_H
    #define MY_H
    #define MAX_PLAYERS 4

char *file(char const *filepath);
unsigned int move_indian(unsigned int ma);
long long put_base_ten(char *nbr, char *base_from);
char *my_addchar(char *str, char c, int pos);
int to_number(char const *str);
int my_strlen(const char *str);
char *my_strndup(char const *src, size_t n);
char *my_strdup(char const *src);
char *my_strncpy(char *dest, char const *src, size_t len);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *concat_strings(char *dest, char const *src);
int my_strlen(const char *str);
int mini_printf(const char *format, ...);
int main(int ac, char **av);
int usage(int ac, char **av);
void fill_header(const char *file_name);

typedef struct champion_s {
    header_t *var;
    char name[PROG_NAME_LENGTH + 1];
    int number;
    int size;
    int load_address;
} champion_t;

typedef struct process_s {
    header_t *header;
    int pc;
    int carry;
    int live;
    int wait_cycles;
    int registries[REG_NUMBER];
    struct process_s *next;
} process_t;

typedef struct vm_s {
    unsigned char memory[MEM_SIZE];
    champion_t *champions;
    int nb_players;
    int cycle;
    int cycle_to_die;
    int live_count;
    int last_live;
    int dump_cycle;
    process_t *processes;
} vm_t;

vm_t *init_vm(void);
void destroy_vm(vm_t *vm);
int load_champion(vm_t *vm, char *filename, int prog_number, int load_address);
void init_display(void);
void display_memory(vm_t *vm);
int run_vm(vm_t *vm);
int parse_args(int ac, char **av, vm_t *vm);;
void op_live(vm_t *vm, process_t *process);
void op_ld(vm_t *vm, process_t *process);
void op_st(vm_t *vm, process_t *process);
void op_add(vm_t *vm, process_t *process);
void op_sub(vm_t *vm, process_t *process);
void op_and(vm_t *vm, process_t *process);
void op_or(vm_t *vm, process_t *process);
void op_xor(vm_t *vm, process_t *process);
void op_zjmp(vm_t *vm, process_t *process);
void op_ldi(vm_t *vm, process_t *process);
void op_sti(vm_t *vm, process_t *process);
void op_fork(vm_t *vm, process_t *process);
void op_lld(vm_t *vm, process_t *process);
void op_lldi(vm_t *vm, process_t *process);
void op_lfork(vm_t *vm, process_t *process);
void op_aff(vm_t *vm, process_t *process);

#endif
