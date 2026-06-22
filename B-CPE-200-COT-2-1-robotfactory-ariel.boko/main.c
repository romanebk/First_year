/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "op.h"
#include "my.h"

header_t remp(header_t head, int ac, char **av)
{
    char *p = opel(av[1]);
    char **ta = my_st(p, '\n');
    char **tab = my_str(p);
    char *t = recup(ta[0], 128);
    char *h = recup(ta[1], 2048);

    head.magic = swap(COREWAR_EXEC_MAGIC);
    my_strcpy(head.prog_name, t);
    for (int i = my_s(t); i < 128; i++)
        head.prog_name[i] = '\0';
    head.prog_name[128] = '\0';
    my_strcpy(head.comment, h);
    for (int i = my_s(h); i < 2048; i++)
        head.comment[i] = '\0';
    head.comment[2048] = '\0';
    return head;
}

void remp1(int ac, char **av)
{
    char *nam = NULL;
    int i = 0;
    FILE *fi;
    header_t head;

    nam = name(av[1]);
    if (my_s(nam) == 0)
        return;
    fi = fopen(nam, "wb");
    if (fi == NULL)
        return;
    head = remp(head, ac, av);
    head.prog_size = swap(22);
    head.magic = COREWAR_EXEC_MAGIC;
    fwrite(&head, sizeof(header_t), 1, fi);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    if (file_d(av[1]) != 0)
        return 84;
    remp1(ac, av);
    return 0;
}
