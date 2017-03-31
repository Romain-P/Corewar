##
## Makefile for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/corewar
## 
## Made by Antonin Rapini
## Login   <antonin.rapini@epitech.net>
## 
## Started on  Fri Mar 31 15:08:49 2017 Antonin Rapini
## Last update Fri Mar 31 15:10:41 2017 Antonin Rapini
##

SRC	= 	corewar.c

OBJ	=	$(SRC:.c=.o)

NAME	= 	corewar

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
