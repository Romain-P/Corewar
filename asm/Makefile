##
## Makefile for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls
## 
## Made by Antonin Rapini
## Login   <antonin.rapini@epitech.net>
## 
## Started on  Tue Nov 29 08:50:17 2016 Antonin Rapini
## Last update Thu Mar 30 10:20:04 2017 Antonin Rapini
##

CFLAGS	+= -Wall -Werror -Wextra
CFLAGS 	+= -I include

SRC	=	utils/my_open_champion.c	\
		utils/my_cor_utils.c		\
		utils/my_memset.c		\
		utils/my_strlen.c		\
		utils/my_strcmp.c		\
		utils/get_next_line.c		\
		utils/my_strncmp.c		\
		utils/my_getfile.c		\
		utils/my_wordtab_utils.c	\
		utils/my_putstr.c		\
		utils/my_putchar.c		\
		utils/my_strndup.c		\
		utils/my_str_to_params.c	\
		utils/my_getnbr.c		\
		utils/my_miniprintf.c		\
		utils/my_put_nbr.c		\
		utils/my_int_tostr.c		\
		utils/my_create_octal.c		\
		utils/my_nbrlen.c		\
		sources/my_write_header.c	\
		sources/my_get_champion.c	\
		sources/my_get_header.c		\
		sources/my_get_code.c		\
		sources/my_get_instruction.c	\
		sources/my_get_label.c		\
		sources/my_get_paramtype.c	\
		sources/my_check_instruction.c	\
		sources/my_instructionlen.c	\
		sources/my_create_corfile.c	\
		asm.c

OBJ	=	$(SRC:.c=.o)

NAME	= 	asm

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
