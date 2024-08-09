/*
** EPITECH PROJECT, 2024
** print_value.c
** File description:
** printer for new value
*/

#include "neutrinos.h"

void print_values(neutrinos_t *value, char *var)
{
    int new_value = atoi(var);
    double ar_mean = arithmetic_mean(value->nb - 1, value->ar_mean, new_value);
    double rms_mean = root_mean_square(value, new_value);
    double har_mean = harmonic_mean(value->nb - 1, value->har_mean, new_value);
    double sd = s_deviation(value, ar_mean, new_value);

    value->ar_mean = ar_mean;
    value->har_mean = har_mean;
    value->sd = sd;
    printf("    Number of values:   %.0f\n", value->nb);
    printf("    Standard deviation: %.2f\n", sd);
    printf("    Arithmetic mean:    %.2f\n", ar_mean);
    printf("    Root mean square:   %.2f\n", rms_mean);
    printf("    Harmonic mean:      %.2f\n\n", har_mean);
}

void checking(char *av)
{
    for (int j = 0; av[j]; j++)
        if (!(av[j] >= '0' && av[j] <= '9'))
            exit(84);
    return;
}
