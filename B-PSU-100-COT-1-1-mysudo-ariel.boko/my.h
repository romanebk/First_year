/*
** EPITECH PROJECT, 2024
** fghjk
** File description:
** fghjkl
*/


#include <stdarg.h>
#ifndef _SUDO_H_
    #define _SUDO_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <crypt.h>

void verify_pwd(int ac, char **av);
char *recup(void);
char *file(char const *filepath);
int my_exec(char *w1, char **w2);
char *error_case_two(int nb_read, int fd, char *buffer);
char *error_case_one(int fd, char *buffer);
int usage(int argc, char **argv);
int main(int argc, char **argv);

#endif
