/*
** EPITECH PROJECT, 2025
** function
** File description:
** parsing
*/

#include "../include/my.h"

void cut_read_line(parse_t *var, char *line, parse_context_t *ctx)
{
    if (ctx->e == 0 && my_strlen(line) > 0 && check_arg(line) == 0)
        var->nb_robot = to_number(line);
    if (ctx->e > 0 && chech_tiret(line) == 1) {
        var->tunnel[ctx->i] = my_strdup(line);
        (ctx->i)++;
    } else if (ctx->e > 0 && chech_tiret(line) != 1) {
        var->room[ctx->j] = my_strdup(line);
        (ctx->j)++;
    }
}

bool skip_line(char *line)
{
    return (line[0] == '\n' || (line[0] == '#' &&
        (my_wordlen(line, '#') - 1 == 1 ||
        my_wordlen(line, '#') - 1 > 2)));
}

parse_t *read_line(void)
{
    char *line = NULL;
    size_t len = 0;
    parse_context_t ctx = {0, 0, 0};
    parse_t *var = alloc_struct();

    while (getline(&line, &len, stdin) != -1) {
        line[my_strlen(line) - 1] = '\0';
        if (skip_line(line))
            continue;
        cut_read_line(var, line, &ctx);
        ctx.e++;
    }
    var->room[ctx.j] = NULL;
    var->tunnel[ctx.i] = NULL;
    free(line);
    return var;
}
