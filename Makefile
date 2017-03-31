##
## Makefile for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar
## 
## Made by Antonin Rapini
## Login   <antonin.rapini@epitech.net>
## 
## Started on  Fri Mar 31 15:03:27 2017 Antonin Rapini
## Last update Fri Mar 31 15:04:16 2017 Antonin Rapini
##

all 	:
		make -C asm/

clean	:
		make clean -C asm/

fclean	:
		make fclean -C asm/

re 	:	fclean all
