/*
** my_instructionlen.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Mar 29 06:33:16 2017 Antonin Rapini
** Last update Thu Mar 30 10:24:35 2017 Antonin Rapini
*/

#include "my_asm.h"

int	my_instructionlen(t_instruct *instruct)
{
  int	len;
  int	i;

  i = 0;
  len = 1;
  len += instruct->codingbyte != -1 ? 1 : 0;
  while (instruct->params[i].param)
    {
      if (instruct->params[i].type == 1)
	len += 1;
      else if (instruct->params[i].type == 2)
	len += 2;
      else if (instruct->params[i].type == 4)
	len += 4;
      i++;
    }
  return (len);
}
