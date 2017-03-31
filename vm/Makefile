##
## makefile for make in tetris
## 
## Made by Romain Pillot
## Login   <romain.pillot@epitech.net>
## 
## Started on  Sat Oct 29 17:09:21 2016 romain pillot
## Last update Thu Mar 30 14:08:50 2017 romain pillot
##

CC	=	gcc

NAME	=	corewar

RM	=	rm -f

SRCS	=	src/main.c			\
		src/option.c			\
		src/list.c			\
		src/encoder.c			\
		src/process.c			\
		src/file.c			\
		src/util/nbr_util.c		\
		src/util/out_util.c		\
		src/util/scanner.c		\
		src/util/tab_util.c		\
		src/util/str_util.c		\
		src/util/str_util_more.c	\
		src/util/str_util_plus.c	\
		src/util/util.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-Iinclude -g #-Werror -Wall -Wextra

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re