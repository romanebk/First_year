/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h
*/

#ifndef MY_H
   #define MY_H

double coefficient_correlation(char *str);
double root_mean_square_dev_2(int argc, char **argv, char *str);
double reel_2(int argc, char **argv, char *str);
double coe_directeur_2(int argc, char **argv, char *str);
double covariance(char *str);
double var_y(int argc, char **argv, char *str);
double root_mean_square_dev(int argc, char **argv, char *str);
double reel(int argc, char **argv);
double coe_directeur(int argc, char **argv);
double sum_pro(char *str);
double sum_y_square(char *str);
double sum_y(char *str);
double sum_x_square();
double sum_x();
int check(char *str);
int pass_code(int argc, char **argv, char *str);
char **my_str_to_word_array(char *str);
char *insert(char **tab, int i);
char *error_case_three(int nb_column, int nb_line, char **tab);
int nb_char(char *str, char c, char d);
int count_separator(char *str, char c, char d);
char *error_case_one(int fd, char *buffer);
char *error_case_two(int nb_read, int fd, char *buffer);
char *file(char const *filepath);
int usage(int argc, char **argv);
int main(int argc, char **argv, char *str);

#endif
