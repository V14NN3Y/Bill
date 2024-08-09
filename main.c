/*
** EPITECH PROJECT, 2024
** 104_Neutrinos
** File description:
** File
*/

#include "neutrinos.h"

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
