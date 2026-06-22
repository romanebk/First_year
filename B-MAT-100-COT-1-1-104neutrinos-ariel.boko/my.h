/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h
*/

#ifndef MY_H
   #define MY_H

double arithmetic_mean(double n, double a, double nv);
double standard_deviation(double a, double nv, double n, double sd);
double harmonic_mean(double h, double n, double nv);
double root_mean_square(double n, double sd, double a, double nv);
void display(double sd, double n, double a, double r, double h);
int my_isdigit_str(char *str);
int usage(int argc, char **argv);
int main(int argc, char **argv);

#endif
