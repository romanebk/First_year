/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#ifndef MY_H
   #define MY_H

int count_vir(char *str);
int check_vir(char *str);
void generate_synthetic_data(double n, double i0, double i1);
int main(int argc, char **argv);
void calcul_population(double n, double k);
int check_arg(char *str);
int usage(int argc, char **argv);

#endif
