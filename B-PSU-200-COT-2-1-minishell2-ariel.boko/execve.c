/*
** EPITECH PROJECT, 2025
** fghjkl
** File description:
** hgfdsq
*/

#include "my.h"

int error_perm(char **args, char **env)
{
    int fd = open(args[0], O_RDONLY);
    DIR *dir = opendir(args[0]);
    int res = 0;

    if (execve(args[0], args, env) == -1) {
        res = 0;
    }
    if ((my_strncmp(args[0], "/", 1) == 0
            || (my_strncmp(args[0], "./", 2) == 0))
        && execve(args[0], args, env) == -1 &&
        (fd != -1 || dir != NULL) && errno != ENOEXEC) {
        res = 2;
        my_putstr_error(args[0]);
        my_putstr_error(": Permission denied.\n");
        return res;
    }
    return 0;
}

int ver(char *str)
{
    int i = 0;
    int res = 0;

    for (; str[i] != '\0'; i++) {
        if ((str[0] == '.' && str[1] == '/') || str[0] == '/')
            res = 1;
    }
    return res;
}

int excution(char *input, char **env, char **args)
{
    int b = ver(input);
    char *concat_path = NULL;

    concat_path = all_path(env, input, args);
    if (error_perm(args, env) == 2)
        return 0;
    if (b == 1 && execve(args[0], args, env) == -1) {
        ommit(args[0]);
        my_putstr_error(args[0]);
        my_putstr_error(": Command not found.\n");
        exit(1);
    } else if (execve(concat_path, args, env) == -1) {
        ommit(args[0]);
        my_putstr_error(args[0]);
        my_putstr_error(": Command not found.\n");
        exit(1);
    }
    free(concat_path);
    return 0;
}

int signale(int status)
{
    if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV) {
        my_putstr_error("Segmentation fault\n");
        return 0;
    }
    if (WCOREDUMP(status)) {
        my_putstr_error("Segmentation fault (core dumped)\n");
        return 0;
    }
    return 0;
}
