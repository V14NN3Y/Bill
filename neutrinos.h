/*
** EPITECH PROJECT, 2024
** neutrinos,h
** File description:
** header file
*/

#ifndef NEUTRINOS_H
    #define NEUTRINOS_H
    #include <string.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <math.h>
    #include <stdio.h>
typedef struct neutrinos {
    double nb;
    double ar_mean;
    double har_mean;
    double sd;
} neutrinos_t;
double s_deviation(neutrinos_t *value, double new_mean, double new_value);
double harmonic_mean(double nb, double old_mean, double new_value);
double root_mean_square(neutrinos_t *value, double new_value);
double arithmetic_mean(double nb, double old_mean, double new_value);
void print_values(neutrinos_t *value, char *var);
void manage(char **av, neutrinos_t *value, char *var);
void checking(char *av);
#endif
