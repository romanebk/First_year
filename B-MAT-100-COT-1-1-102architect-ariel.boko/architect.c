/*
** EPITECH PROJECT, 2024
** architech
** File description:
** architecture
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int usage(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
        printf("USAGE\n    ./102architect x y transfo1 arg11 ");
        printf("[arg12] [transfo2 arg21 [arg22]] ...\n\n\n");
        printf("DESCRIPTION\n");
        printf("    x abscissa of the original point\n");
        printf("    y ordinate of the original point\n");
        printf("    transfo arg1 [arg2]\n");
        printf("    -t i j translation along vector (i, j)\n");
        printf("    -z m n scaling by factors m (x-axis) and n (y-axis)\n");
        printf("    -r d    rotation centered in O by a d degree angle\n");
        printf("    -s d    reflection over the axis passing ");
        printf("through O with an inclination\n");
        printf("            angle of d degrees\n");
    }
    else {
        exit(84);
    }
    return 0;
}

double translation(int argc, char **argv)
{
    double a = 0;
    double b = 0;
    double v[3][3];

    if (argc == 6 && argv[3][0] == '-' && argv[3][1] == 't' && argv[3][2] == '\0') {
        v[0][0] = 1;
        v[0][1] = 0;
        v[0][2] = atof(argv[4]);
        v[1][0] = 0;
        v[1][1] = 1;
        v[1][2] = atof(argv[5]);
        v[2][0] = 0;
        v[2][1] = 0;
        v[2][2] = 1;
        a = ((v[0][0] * atof(argv[1])) + (v[0][1] * atof(argv[2])) + (v[0][2] * 1));
        b = ((v[1][0] * atof(argv[1])) + (v[1][1] * atof(argv[2])) + (v[1][2] * 1));
        printf("Translation along vector (%d, %d)\n", atoi(argv[4]), atoi(argv[5]));
        printf("%.2f   %.2f   %.2f\n", v[0][0], v[0][1], v[0][2]);
        printf("%.2f   %.2f   %.2f\n", v[1][0], v[1][1], v[1][2]);
        printf("%.2f   %.2f   %.2f\n", v[2][0], v[2][1], v[2][2]);
        printf("(%.2f, %.2f)", atof(argv[1]), atof(argv[2]));
        printf(" => ");
        printf("(%.2f, %.2f)\n", a, b);
    }
    else {
        exit(84);
    }
}

double scaling(int argc, char **argv)
{
    double c = 0;
    double d = 0;
    double w[3][3];

    if (argc == 6 && argv[3][0] == '-' && argv[3][1] == 'z' && argv[3][2] == '\0') {
        w[0][0] = atof(argv[4]);
        w[0][1] = 0;
        w[0][2] = 0;
        w[1][0] = 0;
        w[1][1] = atof(argv[5]);
        w[1][2] = 0;
        w[2][0] = 0;
        w[2][1] = 0;
        w[2][2] = 1;
        c = ((w[0][0] * atof(argv[1])) + (w[0][1] * atof(argv[2])) + (w[0][2] * 1));
        d = ((w[1][0] * atof(argv[1])) + (w[1][1] * atof(argv[2])) + (w[1][2] * 1));
        printf("Scaling by factors %d and %d\n", atoi(argv[4]), atoi(argv[5]));
        printf("%.2f   %.2f   %.2f\n", w[0][0], w[0][1], w[0][2]);
        printf("%.2f   %.2f   %.2f\n", w[1][0], w[1][1], w[1][2]);
        printf("%.2f   %.2f   %.2f\n", w[2][0], w[2][1], w[2][2]);
        printf("(%.2f, %.2f)", atof(argv[1]), atof(argv[2]));
        printf(" => ");
        printf("(%.2f, %.2f)\n", c, d);
    }
    else {
        exit(84);
    }
}

double rotation(int argc, char **argv)
{
    double e = 0;
    double f = 0;
    double angle = atof(argv[4]) * ((M_PI) / 180);
    double x[3][3];

    if (argc == 5 && argv[3][0] == '-' && argv[3][1] == 'r' && argv[3][2] == '\0') {
        x[0][0] = cos(angle);
        x[0][1] = -sin(angle);
        x[0][2] = 0;
        x[1][0] = sin(angle);
        x[1][1] = cos(angle);
        x[1][2] = 0;
        x[2][0] = 0;
        x[2][1] = 0;
        x[2][2] = 1;
        e = ((x[0][0] * atof(argv[1])) + (x[0][1] * atof(argv[2])) + (x[0][2] * 1));
        f = ((x[1][0] * atof(argv[1])) + (x[1][1] * atof(argv[2])) + (x[1][2] * 1));
        printf("Rotation by a %d degree angle\n", atoi(argv[4]));
        printf("%.2f   %.2f   %.2f\n", x[0][0], x[0][1], x[0][2]);
        printf("%.2f   %.2f   %.2f\n", x[1][0], x[1][1], x[1][2]);
        printf("%.2f   %.2f   %.2f\n", x[2][0], x[2][1], x[2][2]);
        printf("(%.2f, %.2f)", atof(argv[1]), atof(argv[2]));
        printf(" => ");
        printf("(%.2f, %.2f)\n", e, f);
    }
    else {
        exit(84);
    }
}

double Reflection(int argc, char **argv)
{
    double h = 0;
    double i = 0;
    double angle = atof(argv[4]) * ((M_PI) / 180);
    double y[3][3];

    if (argc == 5 && argv[3][0] == '-' && argv[3][1] == 's' && argv[3][2] == '\0') {
        y[0][0] = cos(2 * angle);
        y[0][1] = sin(2 * angle);
        y[0][2] = 0;
        y[1][0] = sin(2 * angle);
        y[1][1] = -cos(2 * angle);
        y[1][2] = 0;
        y[2][0] = 0;
        y[2][1] = 0;
        y[2][2] = 1;
        h = ((y[0][0] * atof(argv[1])) + (y[0][1] * atof(argv[2])) + (y[0][2] * 1));
        i = ((y[1][0] * atof(argv[1])) + (y[1][1] * atof(argv[2])) + (y[1][2] * 1));
        printf("Reflection over an axis with an inclination angle of %d degrees\n", atoi(argv[4])); 
        printf("%.2f   %.2f   %.2f\n", y[0][0], y[0][1], y[0][2]);
        printf("%.2f   %.2f   %.2f\n", y[1][0], y[1][1], y[1][2]);
        printf("%.2f   %.2f   %.2f\n", y[2][0], y[2][1], y[2][2]);
        printf("(%.2f, %.2f)", atof(argv[1]), atof(argv[2]));
        printf(" => ");
        printf("(%.2f, %.2f)\n", h, i);
    }
    else {
        exit(84);
    }
}

int main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
        usage(argc, argv);
    } else if (argc == 6 && argv[3][0] == '-' && argv[3][1] == 't' && argv[3][2] == '\0') {
        translation(argc, argv);
    } else if (argc == 6 && argv[3][0] == '-' && argv[3][1] == 'z' && argv[3][2] == '\0') {
        scaling(argc, argv);
    } else if (argc == 5 && argv[3][0] == '-' && argv[3][1] == 'r' && argv[3][2] == '\0') {
        rotation(argc, argv);
    } else if (argc == 5 && argv[3][0] == '-' && argv[3][1] == 's' && argv[3][2] == '\0') {
        Reflection(argc, argv);
    }
    else {
	return 84;
    }
}
