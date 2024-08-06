/*
** EPITECH PROJECT, 2024
** 104_Neutrinos
** File description:
** File
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

static double harmonic_mean(double nb, double old_mean, double new_value)
{
    double new_mean = pow((old_mean / nb), -1) + (1 / new_value);

    new_mean = pow(new_mean, -1) * (nb + 1);
    return new_mean;
}

static double root_mean_square(neutrinos_t *value, double new_value)
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

static double arithmetic_mean(double nb, double old_mean, double new_value)
{
    double new_mean = ((old_mean * nb) + new_value) / (nb + 1);

    return new_mean;
}

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

void manage(char **av, neutrinos_t *value, char *var)
{
    value->nb = atoi(av[1]);
    value->ar_mean = atoi(av[2]);
    value->har_mean = atoi(av[3]);
    value->sd = atoi(av[4]);
    var = malloc(sizeof(char) * 100);
    while (1) {
        printf("Enter next value: ");
        scanf("%s", var);
        if (strcmp(var, "END") == 0)
            break;
        value->nb++;
        print_values(value, var);
    }
    free(var);
    free(value);
}

void checking(char *av)
{
    for (int j = 0; av[j]; j++)
        if (!(av[j] >= '0' && av[j] <= '9'))
            exit(84);
    return;
}

int main(int ac, char **av)
{
    neutrinos_t *value = malloc(sizeof(neutrinos_t));
    char *var;

    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        printf("USAGE\n");
        printf("    ./104neutrinos n a h sd\n\n");
        printf("DESCRIPTION\n");
        printf("    n       number of values\n");
        printf("    a       arithmetic mean\n");
        printf("    h       harmonic mean\n");
        printf("    sd      standard deviation\n");
        return 0;
    }
    if (ac == 5) {
        for (int i = 1; av[i]; i++)
            checking(av[i]);
        manage(av, value, var);
        return 0;
    }
    return 84;
}
