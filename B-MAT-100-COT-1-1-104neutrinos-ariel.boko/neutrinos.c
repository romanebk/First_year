/*
** EPITECH PROJECT, 2024
** neutrinos
** File description:
** neutrinos
*/

#include "my.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

double arithmetic_mean(double n, double a, double nv)
{
    double stock_x_a = 0.0;
    double new_a = 0.0;

    stock_x_a = a * n + nv;
    new_a = stock_x_a / (n + 1);
    return new_a;
}

double standard_deviation(double a, double nv, double n, double sd)
{
    double new_a = arithmetic_mean(n, a, nv);
    double new_sd = 0.0;
    double stock_x_sd_p = 0.0;
    double stock_x_sd_n = 0.0;

    stock_x_sd_p = (pow(a, 2) + pow(sd, 2)) * n;
    stock_x_sd_n = stock_x_sd_p + pow(nv, 2);
    new_sd = sqrt(((stock_x_sd_n) / (n + 1)) - (pow(new_a, 2)));
    return new_sd;
}

double harmonic_mean(double h, double n, double nv)
{
    double stock_x_h = 0.0;
    double new_h = 0.0;

    stock_x_h = (n / h) + (1 / nv);
    new_h = (n + 1) / stock_x_h;
    return new_h;
}

double root_mean_square(double n, double sd, double a, double nv)
{
    double rms_pre_po = 0.0;
    double stock_x_r = 0.0;
    double rms_new = 0.0;

    rms_pre_po = pow(sd, 2) + pow(a, 2);
    stock_x_r = rms_pre_po * n + nv * nv;
    rms_new = sqrt(stock_x_r / (n + 1));
    return rms_new;
}

void display(double sd, double n, double a, double r, double h)
{
    printf("    Number of values:   %.0lf\n", n);
    printf("    Standard deviation: %.2lf\n", sd);
    printf("    Arithmetic mean:    %.2lf\n", a);
    printf("    Root mean square:   %.2lf\n", r);
    printf("    Harmonic mean:      %.2lf\n\n", h);
}

int main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' &&
        argv[1][1] == 'h' && argv[1][2] == '\0') {
        usage(argc, argv);
	return 0;
    }
    if (argc != 5)
	return 84;
    double nv = 0.0;
    double r = 0.0;
    double n = atof(argv[1]);
    double a = atof(argv[2]);
    double h = atof(argv[3]);
    double sd = atof(argv[4]);
    char value[100];

    if (argc == 5) {
      for (int i = 1; i < argc; i++) {
	for (int j = 0; argv[i][j] != '\0'; j++) {
	  if (argv[i][j] >= '0' && argv[i][j] <= '9') {
	  } else {
	    return 84;
	  }
	}
      }
    }
    if (n <= 0 || a < 0 || h <= 0 || sd <= 0 || argc != 5)
            return 84;
    if (n == 0 && ( a != 0 || h != 0 || sd != 0))
          return 84;
    while (1) {
        printf("Enter next value: ");
	if (scanf("%99s", value) != 1)
	  continue;
        if (strcmp(value, "END") == 0)
            break;
	for (int j = 0; value[j] != '\0'; j++) {
          if (value[j] >= '0' && value[j] <= '9') {
          } else {
            return 84;
          }
        }
        nv = atof(value);
	if (nv <= 0)
	    return 84;
        r = root_mean_square(n, sd, a, nv);
        sd = standard_deviation(a, nv, n, sd);
	a = arithmetic_mean(n, a, nv);
        h = harmonic_mean(h, n, nv);
        n++;
        display(sd, n, a, r, h);
    }
    return 0;
}
