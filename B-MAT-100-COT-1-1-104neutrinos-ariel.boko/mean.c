/*
** EPITECH PROJECT, 2025
** dfg
** File description:
** lkjh
*/

double arithmetic_mean(double n, double a, double nv)
{
    double stock_x_a = 0.0;
    double new_a = 0.0;

    stock_x_a = a * n + nv;
    new_a = stock_x_a / (n + 1);
    return new_a;
}
