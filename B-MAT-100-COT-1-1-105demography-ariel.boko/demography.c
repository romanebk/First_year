/*
** EPITECH PROJECT, 2024
** demography
** File description:
** demography
*/

#include <string.h>
#include <math.h>
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

double sum_x()
{
    char *content = file("105demography_data.csv");
    char **date = my_str_to_word_array(content);
    double res = 0;

    if (content == NULL)
        return 84;
    if (date == NULL) {
        free(content);
        return 84;
    }
    for (int i = 2; i < 60; i++) {
        res = res + atof(date[i]);
        free(date[i]);
    }
    free(date);
    free(content);
    return res;
}

double sum_x_square()
{
    char *content = file("105demography_data.csv");
    char **date = my_str_to_word_array(content);
    double res = 0;

    if (content == NULL)
	return 84;
    if (date == NULL) {
	free(content);
        return 84;
    }
    for (int i = 2; i < 60; i++) {
        res = res + pow(atof(date[i]), 2);
        free(date[i]);
    }
    free(date);
    free(content);
    return res;
}

double sum_y(char *str)
{
    char *content = file("105demography_data.csv");
    char **pop = my_str_to_word_array(content);
    double res = 0.0;

    if (content == NULL)
        return 84;
    if (pop == NULL) {
        free(content);
        return 84;
    }
    for (int k = 0; pop[k] != NULL ; k++) {
        if (strcmp(pop[k], str) == 0) {
            for (int i = k + 1; i < k + 59; i++) {
                res = res + atof(pop[i]);
                free(pop[i]);
            }
        }
    }
    free(content);
    free(pop);
    return res;
}

double sum_y_square(char *str)
{
    char *content = file("105demography_data.csv");
    char **pop = my_str_to_word_array(content);
    double res = 0.0;

    if (content == NULL)
	return 84;
    if (pop == NULL) {
        free(content);
        return 84;
    }
    for (int k = 0; pop[k] != NULL ; k++) {
	if (strcmp(pop[k], str) == 0) {
            for (int i = k + 1; i < k + 59; i++) {
                res = res + pow(atof(pop[i]), 2);
                free(pop[i]);
            }
        }
    }
    free(content);
    free(pop);
    return res;
}

double sum_pro(char *str)
{
    char *content = file("105demography_data.csv");
    char **tab1 = my_str_to_word_array(content);
    char **tab2 = my_str_to_word_array(content);
    int o = 2;
    int j = 0;
    double res = 0;

    if (content == NULL)
        return 84;
    if (tab1 == NULL) {
        free(content);
        return 84;
    }
    if (tab2 == NULL) {
        free(content);
        return 84;
    }
    for (int k = 0; tab1[k] != NULL && tab2[k] != NULL ; k++) {
        if (strcmp(tab2[k], str) == 0) {
          for (int i = k + 1; o < 60 && i < k + 59; i++, o++) {
              res = res + atof(tab1[o]) * atof(tab2[i]);
              free(tab1[o]);
	      free(tab2[i]);
            }
        }
    }
    free(tab1);
    free(tab2);
    return res;
}

double coe_directeur(int argc, char **argv)
{
    double N = 58;
    int i = 1;
    double a = 0.0;
    double s_x = 0.0;
    double s_q_x = 0.0;
    double s_y = 0.0;
    double s_x_y = 0.0;

    s_x = sum_x();
    s_q_x = sum_x_square();
    s_y = sum_y(argv[i]);
    s_x_y = sum_pro(argv[i]);
    a = ((N * s_x_y) - (s_x * s_y)) / ((s_q_x * N) - pow(s_x, 2));
    return a;
}

double reel(int argc, char **argv)
{
    double N = 58;
    int i = 1;
    double b = 0.0;
    double s_x = 0.0;
    double s_q_x = 0.0;
    double s_y = 0.0;
    double s_x_y = 0.0;

    //while (i < argc) {
        s_x = s_x + sum_x();
        s_q_x = s_q_x + sum_x_square();
        s_y = s_y + sum_y(argv[i]);
        s_x_y = s_x_y + sum_pro(argv[i]);
        //i++;
	//}
	b = ((s_y * s_q_x) - (s_x * s_x_y)) / ((N * s_q_x) - (pow(s_x, 2)));
    return b;
}

double root_mean_square_dev(int argc, char **argv, char *str)
{
    double N = 58;
    double a = coe_directeur(argc, argv);
    double b = reel(argc, argv);
    char *content = file("105demography_data.csv");
    char **tab1 = my_str_to_word_array(content);
    char **tab2 = my_str_to_word_array(content);
    int o = 2;
    int j = 0;
    double res = 0;

    if (content == NULL)
        return 84;
    if (tab1 == NULL) {
        free(content);
        return 84;
    }
    if (tab2 == NULL) {
        free(content);
        return 84;
    }
    for (int k = 0; tab1[k] != NULL && tab2[k] != NULL ; k++) {
        if (strcmp(tab2[k], str) == 0) {
          for (int i = k + 1; o < 60 && i < k + 59; i++, o++) {
              res = res + pow((atof(tab2[i]) - ((a * atof(tab1[o])) + b)), 2);
	      free(tab1[i]);
              free(tab2[o]);
            }
        }
    }
    free(tab1);
    free(tab2);
    return sqrt(res / N) / 1000000;
}

double var_y(int argc, char **argv, char *str)
{
    char *content = file("105demography_data.csv");
    char **tab1 = my_str_to_word_array(content);
    char **tab2 = my_str_to_word_array(content);
    int o = 2;
    int j = 0;
    double res = 0;
    double a = coe_directeur(argc, argv);
    double b = reel(argc, argv);
    double N = 58;

    if (content == NULL)
        return 84;
    if (tab1 == NULL) {
        free(content);
        return 84;
    }
    if (tab2 == NULL) {
        free(content);
        return 84;
    }
    for (int k = 0; tab1[k] != NULL && tab2[k] != NULL ; k++) {
        if (strcmp(tab2[k], str) == 0) {
          for (int i = k + 1; o < 60 && i < k + 59; i++, o++) {
	      res = res + pow((atof(tab2[i]) - (sum_y(str) / N)), 2);
              free(tab1[o]);
              free(tab2[i]);
	    }
        }
    }
    free(tab1);
    free(tab2);
    return (res / N);
}

double covariance(char *str)
{
    double N = 58;
    char *content = file("105demography_data.csv");
    char **tab1 = my_str_to_word_array(content);
    char **tab2 = my_str_to_word_array(content);
    int o = 2;
    int j = 0;
    double res = 0.0;

    if (content == NULL)
        return 84;
    if (tab1 == NULL) {
        free(content);
        return 84;
    }
    if (tab2 == NULL) {
        free(content);
        return 84;
    }
    for (int k = 0; tab1[k] != NULL && tab2[k] != NULL ; k++) {
        if (strcmp(tab2[k], str) == 0) {
          for (int i = k + 1; o < 60 && i < k + 59; i++, o++) {
              res = res + (atof(tab1[o]) - (sum_x() / N)) * (atof(tab2[i]) - (sum_y(str) / N));
	      free(tab1[o]);
              free(tab2[i]);
            }
        }
    }
    free(tab1);
    free(tab2);
    return (res * (1 / N));
}

double coe_directeur_2(int argc, char **argv, char *str)
{
    double cov_x_y = covariance(str);
    double v_y = var_y(argc, argv, str);
    double N = 58;
    double a = 0.0;
    double s_x = 0.0;
    double s_q_x = 0.0;
    double s_y = 0.0;
    double s_x_y = 0.0;
    double s_q_y = 0.0;

    return (cov_x_y / v_y) * 1000000;
}

double reel_2(int argc, char **argv, char *str)
{
    double N = 58;
    int i = 1;
    double b = 0.0;
    double s_x = 0.0;
    double s_q_x = 0.0;
    double s_y = 0.0;
    double s_x_y = 0.0;
    double s_q_y = 0.0;

    s_x = s_x + sum_x();
    s_q_x = s_q_x + sum_x_square();
    s_q_y = s_q_y + sum_y_square(str);
    s_y = s_y + sum_y(argv[i]);
    s_x_y = s_x_y + sum_pro(argv[i]);
    b = ((s_x * s_q_y) - (s_y * s_x_y)) / ((N * s_q_y) - (pow(s_y, 2)));
    return b;
}

double root_mean_square_dev_2(int argc, char **argv, char *str)
{
    double N = 58;
    double a = coe_directeur_2(argc, argv, argv[1]);
    double b = reel_2(argc, argv, argv[1]);
    char *content = file("105demography_data.csv");
    char **tab1 = my_str_to_word_array(content);
    char **tab2 = my_str_to_word_array(content);
    int o = 2;
    int j = 0;
    double res = 0;

    if (content == NULL)
        return 84;
    if (tab1 == NULL) {
        free(content);
        return 84;
    }
    if (tab2 == NULL) {
	free(content);
        return 84;
    }
    for (int k = 0; tab1[k] != NULL && tab2[k] != NULL ; k++) {
        if (strcmp(tab2[k], str) == 0) {
          for (int i = k + 1; o < 60 && i < k + 59; i++, o++) {
            res = res + pow((atof(tab2[i]) - ((atof(tab1[o]) - b) / a)), 2);
              free(tab1[i]);
              free(tab2[o]);
            }
        }
    }
    free(tab1);
    free(tab2);
    return sqrt(res / N) / 1000000;
}

double coefficient_correlation(char *str)
{
    double N = 58;
    char *content = file("105demography_data.csv");
    char **tab1 = my_str_to_word_array(content);
    char **tab2 = my_str_to_word_array(content);
    int o = 2;
    int j = 0;
    double res = 0.0;
    double res1 = 0.0;
    double res2 = 0.0;

    if (content == NULL)
        return 84;
    if (tab1 == NULL) {
        free(content);
        return 84;
    }
    if (tab2 == NULL) {
        free(content);
        return 84;
    }
    for (int k = 0; tab1[k] != NULL && tab2[k] != NULL ; k++) {
        if (strcmp(tab2[k], str) == 0) {
          for (int i = k + 1; o < 60 && i < k + 59; i++, o++) {
              res = res + (atof(tab1[o]) - (sum_x() / N)) * (atof(tab2[i]) - (sum_y(str) / N));
              res1 = res1 + (atof(tab1[o]) - (sum_x() / N));
              res2 = res2 + (atof(tab2[i]) - (sum_y(str) / N));
              free(tab1[o]);
              free(tab2[i]);
            }
          break;
        }
    }
    free(tab1);
    free(tab2);
    return res / (res1 * res2);
}
