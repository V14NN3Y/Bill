/*
** EPITECH PROJECT, 2024
** B-PSU-200-COT-2-2-minishell1-bill.adjagboni
** File description:
** my_strcmp
*/

#include <stdio.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i]) {
        if (s1[i] == '\0') {
            return 0;
        }
        i = i + 1;
    }
    if (s1[i] > s2[i]) {
        return 1;
    }
    else {
        return -1;
    }
}