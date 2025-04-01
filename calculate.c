/*
** EPITECH PROJECT, 2024
** calculate.c
** File description:
** all the function we used for calculation
*/

#include "neutrinos.h"

double s_deviation(neutrinos_t *value, double new_mean, double new_value)
{
    double sd = value->sd * value->sd;

    sd = sd * (value->nb - 1);
    sd = sd + (new_value - new_mean) * (new_value - value->ar_mean);
    sd = sd / value->nb;
    sd = sqrt(sd);
    return sd;
}

double harmonic_mean(double nb, double old_mean, double new_value)
{
    double new_mean = pow((old_mean / nb), -1) + (1 / new_value);

    new_mean = pow(new_mean, -1) * (nb + 1);
    return new_mean;
}

double root_mean_square(neutrinos_t *value, double new_value)
{
    double nb = value->nb;
    double ar_mean = value->ar_mean;
    double sd = value->sd;
    double rms = sqrt(pow(sd, 2) + pow(ar_mean, 2));

    rms = rms * rms;
    rms = rms * (nb - 1);
    rms = rms + pow(new_value, 2);
    rms = rms / nb;
    rms = sqrt(rms);
    return rms;
}

double arithmetic_mean(double nb, double old_mean, double new_value)
{
    double new_mean = ((old_mean * nb) + new_value) / (nb + 1);

    return new_mean;
}
