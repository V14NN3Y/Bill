##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## makefile for 104 neutrinos
##

SRC = main.c

all:
	gcc -o 104neutrinos $(SRC) -lm

clean:
	rm -f *~
	rm -f *#

fclean: clean
	rm -f 104neutrinos

re: fclean all
