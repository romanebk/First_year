/*
** EPITECH PROJECT, 2025
** recoding the command cd
** File description:
** function
*/

#include "my.h"

int chdirector(char *dir, char **args)
{
    if (chdir(dir) != 0) {
        cut_error_cd(args);
        return 1;
    }
    return 0;
}

int recode_cd(char **env, char *input, char **args)
{
    static char *oldpwd = NULL;
    char *dir = NULL;
    char *current_dir = getcwd(NULL, 0);
    int res = 1;

    if (!current_dir) {
        perror("getcwd");
        return 1;
    }
    dir = recode_flag(args, oldpwd, env);
    if (!dir) {
        free(current_dir);
        return 1;
    }
    if (chdirector(dir, args) == 0) {
        update_pwd(&oldpwd, current_dir);
        res = 0;
    } else
        free(current_dir);
    return res;
}
