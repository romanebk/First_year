/*
** EPITECH PROJECT, 2024
** 101pong.c
** File description:
** game
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int usage(int argc, char **argv)
{
    if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
        printf("USAGE\n    ./101pong x0 y0 z0 x1 y1 z1 n\n\n\n");
        printf("DESCRIPTION\n");
        printf("    x0 ball abscissa at time t - 1\n");
        printf("    y0 ball ordinate at time t - 1\n");
        printf("    z0 ball altitude at time t - 1\n");
        printf("    x1 ball abscissa at time t\n");
        printf("    y1 ball ordinate at time t\n");
        printf("    z1 ball altitude at time t\n");
        printf("    n time shift (greater than or equal to zero, integer)\n");
    }
    return 0;
}

int incidence(char **argv, double *k, double *v)
{
    double i = sqrt(pow(v[0], 2) + pow(v[1], 2) + pow(v[2], 2));
    double j = asin((v[2] / i));
    double o = fabs(j * (180 / M_PI));

    v = malloc(sizeof(double) * 3);
    if ((atof(argv[6]) < 0 && k[2] > 0) || (atof(argv[6]) > 0 && k[2] < 0)) {
        printf("The incidence angle is: \n%.2lf degrees\n", o);
    } else {
        printf("The ball won't reach the paddle.\n");
    }
    return 0;
    free(k);
}

double velocity(int argc, char **argv)
{
    double *v = malloc(sizeof(double) * 3);
    double *k = malloc(sizeof(double) * 3);

    v[0] = atof(argv[4]) - atof(argv[1]);
    v[1] = atof(argv[5]) - atof(argv[2]);
    v[2] = atof(argv[6]) - atof(argv[3]);
    v[3] = atoi(argv[7]);
    k[0] = (v[0] * v[3]) + atof(argv[4]);
    k[1] = (v[1] * v[3]) + atof(argv[5]);
    k[2] = (v[2] * v[3]) + atof(argv[6]);
    printf("The velocity vector of the ball is");
    printf(":\n(%.2lf, %.2lf, %.2lf)\n", v[0], v[1], v[2]);
    printf("At time t + %.0lf, ball coordinates will be", v[3]);
    printf(":\n(%.2lf, %.2lf, %.2lf)\n", k[0], k[1], k[2]);
    incidence(argv, k, v);
    free(v);
}

int main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        usage(argc, argv);
        return 0;
    }
    if (argc != 8) {
        return 84;
    } else if (atoi(argv[7]) < 0) {
        return 84;
    }
    velocity(argc, argv);
}
