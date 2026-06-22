/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include "../include/my.h"

int main(int argc, char **argv)
{
    char **map = NULL;
    char *file_content;
    double *arr;
    double *tab;
    int r = 0;
    double *derivative = NULL;
    double *second_derivative = NULL;
    double *second_derivate_est = NULL;
    double equi_point = 0.0;
    double k = 0.0;
    int i = 0;

    if (argc != 2)
        return 84;
    if (argc  == 2)
    {
	if (strcmp(argv[1], "-h") == 0) {
	    usage(argc, argv);
	    return 0;
	} else {
	    file_content = open_file(argv[1]);
	    if (!file_content || strlen(file_content) == 0)
		exit(84);
	    map = parsing(file_content, ";\n");
	    arr = range_volume(map, &r);
	    tab = range_ph(map, &r);
	    derivative = derivate(tab, arr, r);
	    printf("Derivative:\n");
	    for (int i = 1; i < r - 1; i++)
	    {
		printf("%.1f ml -> %.2f\n", arr[i], derivative[i]);
	    }
	    equi_point = find_max(arr, derivative, r);
	    printf("\nEquivalence point at %.1f ml\n", equi_point);
	}
	printf("\nSecond derivative:\n");
	second_derivative = derivate(derivative, arr, r); 
	for (int i = 2; i < r - 2; i++)
	{
	    printf("%.1f ml -> %.2f\n", arr[i], second_derivative[i]);
	}
	printf("\nSecond derivative estimated:\n");
	interpolate_second_derivative(arr, second_derivative, r, equi_point);
	
    }
}
    
