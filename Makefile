##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## makefile for 104 neutrinos
##

SRC = 	print_value.c\
	calculate.c

all:
	gcc -o 104neutrinos $(SRC) main.c -lm

clean:
	rm -f *~
	rm -f *#
	rm -f *.gcno
	rm -f *.gcda


fclean: clean
	rm -f 104neutrinos
	rm -f unit_tests

re: fclean all

unit_tests: fclean
	gcc -o unit_tests $(SRC) tests/test_neutrinos.c -lcriterion --coverage -lm

tests_run: unit_tests
	./unit_tests
