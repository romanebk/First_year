/*
** EPITECH PROJECT, 2025
** function
** File description:
** parsing
*/

#include "../include/my.h"

int load_champion(vm_t *vm, char *filename, int number, int load_address)
{
    int player_index = vm->nb_players;
    FILE *file;
    header_t header;
    unsigned char *buffer = malloc(sizeof(char) * 700);
    size_t read_size;

    file = fopen(filename, "r");
    if (file == NULL) {
        free(buffer);
        return 84;
    }
    if (fread(&header, sizeof(header_t), 1, file) != 1) {
        fclose(file);
        free(buffer);
        return 84;
    }
    read_size = fread(buffer, sizeof(char), 700, file);
    if (read_size <= 0) {
        fclose(file);
        free(buffer);
        return 84;
    }
    fclose(file);
    vm->champions[player_index].size = read_size;
    if (number != 0)
        vm->champions[player_index].number = number;
    else
        vm->champions[player_index].number = player_index + 1;
    if (load_address != -1)
        vm->champions[player_index].load_address = load_address;
    else
        vm->champions[player_index].load_address = (MEM_SIZE / 4) * player_index;
    my_strncpy(vm->champions[player_index].name, header.prog_name, PROG_NAME_LENGTH);
    vm->champions[player_index].name[PROG_NAME_LENGTH] = '\0';
    for (int i = 0; i < read_size && i < 700; i++)
        vm->memory[(vm->champions[player_index].load_address + i)] = buffer[i];
    free(buffer);
    return 0;
}

int parse_args(int ac, char **av, vm_t *vm)
{
    int i = 1;
    int next_number = 0;
    int next_address = -1;
    int dump_cycles = -1;

    while (i < ac) {
        if (strcmp(av[i], "-dump") == 0) {
            dump_cycles =  CYCLE_TO_DIE;
            if (i + 1 < ac && av[i + 1][0] != '-') {
                dump_cycles = atoi(av[i + 1]);
                i += 2;
            } else {
                i++;
            }
        }
        if (strcmp(av[i], "-n") == 0) {
            if (i + 1 >= ac || av[i + 1][0] == '-')
                return 84;
            next_number = atoi(av[i + 1]);
            i += 2;
        }
        if (strcmp(av[i], "-a") == 0) {
            if (i + 1 >= ac || av[i + 1][0] == '-')
                return 84;
            next_address = atoi(av[i + 1]);
            i += 2;
        }
        if (load_champion(vm, av[i], next_number, next_address) != 0) {
            fprintf(stderr, "Erreur: Impossible de charger le champion %s\n", av[i]);
            return 84;
        }
        next_number = 0;
        next_address = -1;
        vm->nb_players++;
        i++;
    }
    if (dump_cycles >= 0)
        vm->cycle_to_die = dump_cycles;
    return 0;
}

vm_t *init_vm(void)
{
    vm_t *vm = malloc(sizeof(vm_t));

    if (vm == NULL)
        return NULL;
    for (int i = 0; i < MEM_SIZE; i++)
        vm->memory[i] = 0;
    vm->nb_players = 0;
    vm->cycle = 0;
    vm->cycle_to_die = 0;
    vm->live_count = 0;
    vm->last_live = 0;
    vm->processes = NULL;
    vm->dump_cycle = -1;
    vm->champions = malloc(sizeof(champion_t) * 4);
    for (int i = 0; i < 4; i++) {
        vm->champions[i].number = i + 1;
        vm->champions[i].load_address = (MEM_SIZE / 4) * i;
        vm->champions[i].size = 0;
    }
    return vm;
}

void destroy_vm(vm_t *vm)
{
    process_t *tmp;

    while (vm->processes != NULL) {
        tmp = vm->processes;
        vm->processes = vm->processes->next;
        free(tmp);
    }
    free(vm->champions);
    free(vm);
}
