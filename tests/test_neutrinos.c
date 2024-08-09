/*
** EPITECH PROJECT, 2024
** test_neutrinos,c
** File description:
** unit tets for 104neutrinos
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../neutrinos.h"

Test(neutrinos_tests, test_s_deviation)
{
    neutrinos_t value = {12000, 297514, 297912, 4363};
    double new_mean = 297514.13;
    double new_value = 299042;
    double expected_result = 4362.84;
    double result = s_deviation(&value, new_mean, new_value);
    cr_assert_float_eq(result, expected_result, 0.01, "incorrect value");
}

Test(neutrinos_tests, neq_test_s_deviation)
{
    neutrinos_t value = {12000, 297514, 297912, 4363};
    double new_mean = 297514.13;
    double new_value = 299042;
    double nt_expected_result = 4362;
    double result = s_deviation(&value, new_mean, new_value);
    cr_assert_float_neq(result, nt_expected_result, 0.01, "incorrect value");
}

Test(neutrinos_tests, test_harmonic_mean)
{
    double nb = 12000;
    double old_mean = 297912;
    double new_value = 299042;
    double expected_result = 297912.09;
    double result = harmonic_mean(nb, old_mean, new_value);
    cr_assert_float_eq(result, expected_result, 0.01, "incorrect value");
}

Test(neutrinos_tests, neq_test_harmonic_mean)
{
    double nb = 12000;
    double old_mean = 297912;
    double new_value = 299042;
    double nt_expected_result = 297912;
    double result = harmonic_mean(nb, old_mean, new_value);
    cr_assert_float_neq(result, nt_expected_result, 0.01, "incorrect value");
}

Test(neutrinos_tests, test_root_mean_square)
{
    neutrinos_t value = {12000, 297514, 297912, 4363};
    double new_value = 299042;
    double expected_result = 297546.11;
    double result = root_mean_square(&value, new_value);
    cr_assert_float_eq(result, expected_result, 0.01, "incorrect value");
}

Test(neutrinos_tests, neq_test_root_mean_square)
{
    neutrinos_t value = {12000, 297514, 297912, 4363};
    double new_value = 299042;
    double nt_expected_result = 297546;
    double result = root_mean_square(&value, new_value);
    cr_assert_float_neq(result, nt_expected_result, 0.01, "incorrect value");
}

Test(neutrinos_tests, test_arithmetic_mean)
{
    double nb = 12000;
    double old_mean = 297514;
    double new_value = 299042;
    double expected_result = 297514.13;
    double result = arithmetic_mean(nb, old_mean, new_value);
    cr_assert_float_eq(result, expected_result, 0.01, "incorrect value");
}

Test(neutrinos_tests, neq_test_arithmetic_mean)
{
    double nb = 12000;
    double old_mean = 297514;
    double new_value = 299042;
    double nt_expected_result = 297514;
    double result = arithmetic_mean(nb, old_mean, new_value);
    cr_assert_float_neq(result, nt_expected_result, 0.01, "incorrect value");
}

Test(tests, test_print_values)
{
    neutrinos_t *value = malloc(sizeof(neutrinos_t));
    char *var = "10";

    value->nb = 1;
    value->ar_mean = 10;
    value->har_mean = 10;
    value->sd = 0;

    cr_redirect_stdout();
    print_values(value, var);
    fflush(stdout);
    cr_assert_stdout_eq_str("    Number of values:   1\n    Standard deviation: 0.00\n    Arithmetic mean:    10.00\n    Root mean square:   10.00\n    Harmonic mean:      10.00\n\n");
}

Test(tests, test_checking)
{
    char *av = "123";
    checking(av);
}

/* Test(checking, should_exit_with_84_when_non_digit_character_is_present) */
/* { */
/*     cr_redirect_stderr(); */
/*     char *av = "123a"; */
/*     cr_expect_fail(checking(av), 84, "Expected 84"); */
/* } */
