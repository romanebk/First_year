/*
** EPITECH PROJECT, 2025
** fghjùgfds
** File description:
** gfds
*/

#include "my.h"

char *get_oldpwd(char *oldpwd)
{
    if (oldpwd == NULL)
    return oldpwd;
}

void update_pwd(char **oldpwd, char *current_pwd)
{
    if (*oldpwd)
        free(*oldpwd);
    *oldpwd = current_pwd;
}

char *recode_flag(char **args, char *oldpwd, char **env)
{
    char *dir = NULL;

    if (args[1] == NULL || my_strcmp(args[1], "~") == 0)
        dir = recup_home(env);
    else if (my_strcmp(args[1], "-") == 0)
        dir = get_oldpwd(oldpwd);
    else
        dir = args[1];
    return dir;
}

int mini_cut_error_cd(char **args)
{
    if (my_strcmp(args[0], "cd") == 0 && args[1] != NULL
        && args[2] != NULL) {
        ommit(args[0]);
        my_putstr_error(args[0]);
        my_putstr_error(": Too many arguments.\n");
        return 2;
    }
    return 0;
}

void cut_error_cd(char **args)
{
    if (mini_cut_error_cd(args) == 2)
        return;
    if (errno == ENOENT) {
        ommit(args[0]);
        my_putstr_error(args[1]);
        my_putstr_error(": No such file or directory.\n");
        return;
    }
    if (errno == ENOTDIR) {
        ommit(args[1]);
        my_putstr_error(args[1]);
        my_putstr_error(": Not a directory.\n");
        return;
    }
    if (errno == EACCES) {
        ommit(args[0]);
        my_putstr_error(args[0]);
        my_putstr_error(": Permission denied.\n");
        return;
    }
}
