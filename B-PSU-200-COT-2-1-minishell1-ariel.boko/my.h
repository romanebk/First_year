/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my.h
*/

#include <dirent.h>
#include <errno.h>
#include <stdarg.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#ifndef _MY_H_
    #define _MY_H_
    #define COLOR "\033[0m"
    #define GREEN "\033[1;32m"
    #define BLUE "\033[1;34m"

//void redirection1(char **args, char **env);
void ommit(char *str1);
int excution(char *input, char **env, char **args);
void cut_error_cd(char **args);
int mini_cut_error_cd(char **args);
int chdirector(char *dir, char **args);
int my_strncmp(char const *s1, char const *s2, int n);
int error_perm(char **args, char **env);
void update_pwd(char **oldpwd, char *cuurent_pwd);
char *get_oldpwd(char *oldpwd);
char *recode_flag(char **args, char *oldpwd, char **env);
int error_cd(char *input, char **args);
int my_putstr_error(char const *str);
void my_putchar_error(char c);
int signale(int status);
char *recup_old(char **env);
char *recup_home(char **env);
int cut_execute_command(char *input, char **args, char **env);
int prompt(char **argv, char **env);
int execute_command(char *input, char **env);
char **com_line(char *input);
char *my_strcpy(char *dest, char const *src);
char *concat_strings(char *dest, char const *src);
int my_execve(char *input, char **env, char **args);
char *my_strcpy(char *dest, char const *src);
char *all_path(char **env, char *input, char **args);
int signale(int status);
int print_env(char **env);
char *ret_path(char **env);
int recode_cd(char **env, char *input, char **args);
int count_separator(char *str, char c);
char *concat_strings(char *dest, char const *src);
char **recupe_command(char **args, char *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char const *src);
int my_strlen(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int mini_printf(const char *format, ...);
int main(int argc, char **argv, char **env);

#endif
