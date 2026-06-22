/*
** EPITECH PROJECT, 2025
** 
** File description:
** 
*/

#include "../include/my.h"

void interpolate_second_derivative(double *arr, double *second_derivative, int r, double equi_point) {
    
    double *before = malloc(sizeof(double) * r);
    double *after = malloc(sizeof(double) * r);
    double *vol = malloc(sizeof(double) * (r * 2));

    int count = 0;
    int i = 0;
    int j = 0;
    int a = 0;

    while (i < r - 1 && arr[i] < equi_point)
	i++;   
    if (i == 0 || i >= r - 1) 
	return;

    double start_before = arr[i - 1];
    double end_before = arr[i];
    double d_start_before = second_derivative[i - 1];
    double d_end_before = second_derivative[i];
    double start_after = arr[i];
    double end_after = arr[i + 1];
    double d_start_after = second_derivative[i];
    double d_end_after = second_derivative[i + 1];
 
    for (double k = start_before; k <= end_before; k += 0.1) {
	double interpolated = d_start_before + ((k - start_before) / (end_before - start_before)) * (d_end_before - d_start_before);
	before[a] = interpolated;
	vol[count] = k;
	count++;
	a++;
	printf("%.1f ml -> %.2f\n", k, interpolated);
    }
    for (double k = start_after + 0.1; k <= end_after; k += 0.1) {
	double interpolated = d_start_after + ((k - start_after) / (end_after - start_after)) * (d_end_after - d_start_after);
	after[j] = interpolated;
	vol[count] = k;
	count++;
	j++;
	printf("%.1f ml -> %.2f\n", k, interpolated);
    }
    double *total = (double*)malloc(sizeof(double) * a * j);

      memcpy(total, before, a * sizeof(double));
      memcpy(total + a, after, j * sizeof(double));  
      double last = last_point(vol, total, a + j);
      printf("\nEquivalence point at %.1f ml\n", last);
}
