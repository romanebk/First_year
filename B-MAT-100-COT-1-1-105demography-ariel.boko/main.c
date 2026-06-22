/*
** EPITECH PROJECT, 2024
** dfghjk
** File description:
** hgfd
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int is_alpha(char c)
{
    if (c >= 'A' && c <= 'Z') {
        return 0;
    } else {
        return 84;
    }
}

int main(int argc, char **argv, char *str)
{
    int j = 0;

    if (argc == 1)
        return 84;
    /*for (int u = 1; u < argc; u++) {
        if (strlen(argv[u]) != 3)
            return 84;
    }*/
    int i = 0;
    double a1 = coe_directeur(argc, argv);
    double b1 = reel(argc, argv);
    double rmsd1 = root_mean_square_dev(argc, argv, str);
    double pop1 = a1 * (2050) + b1;
    double a2 = coe_directeur_2(argc, argv, argv[1]);
    double b2 = reel_2(argc, argv, argv[1]);
    double rmsd2 = root_mean_square_dev_2(argc, argv, argv[1]);
    double pop2 = 0.0;
    double r = 0.0;
    /*
    for (int e = 1; e < argc; e++) {
      int i = 0;
      while (argv[e][i] != '\0') {
	if (is_alpha(argv[e][i] == 0)) {
	  i++;
	} else {
	  return 84;
	}
    }
      i = 0;
    }
    for (int i = 0; i < argc; i++) {
      if (strlen(argv[i]) != 3) {
	return 84;
      }
      }*/
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
        usage(argc, argv);
	return 0;
    } else {
    printf("Country: ");
    while (i < argc) {
        pass_code(argc, argv, argv[i]);
        i++;
    }
    putchar('\n');
    printf("Fit1\n");
    if (b1 < 0) {
        printf("    Y = %.2f X - %.2f\n", a1 / 1000000, -(b1 / 1000000));
    } else {
        printf("    Y = %.2f X + %.2f\n", a1 / 1000000, b1/ 1000000);
    }
    printf("    Root-mean-square deviation: %.2f\n", root_mean_square_dev(argc, argv, argv[1]));
    printf("    Population in 2050: %.2f\n", pop1 / 1000000);
    printf("Fit2\n");
    if (b2 < 0) {
        printf("    X = %.2f Y + %.2f\n", a2, -b2);
    } else {
        printf("    X = %.2f Y + %.2f\n", a2, b2);
    }
    printf("    Root-mean-square deviation: %.2f\n", rmsd2);
    pop2 = (2050 - b2) / a2;
    printf("    Population in 2050: %.2f\n", pop2);
    printf("Correlation: %.2f\n", r);
    return 0;
    }
}
