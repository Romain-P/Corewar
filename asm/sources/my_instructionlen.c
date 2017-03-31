/*
** my_instructionlen.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Mar 29 06:33:16 2017 Antonin Rapini
** Last update Fri Mar 31 10:48:18 2017 Antonin Rapini
*/

#include "my_asm.h"

int	my_instructionlen(t_instruct *instruct)
{
  int	len;
  int	i;
  int	usesindex;

  usesindex = (instruct->code >= 9 && instruct->code <= 15)
    && instruct->code != 13;
  i = 0;
  len = 1;
  len += instruct->codingbyte != -1 ? 1 : 0;
  while (instruct->params[i].param)
    {
      if (instruct->params[i].type == T_REG)
	len += 1;
      else if (instruct->params[i].type == T_IND || usesindex)
	len += 2;
      else if (instruct->params[i].type == T_DIR)
	len += 4;
      i++;
    }
  return (len);
}
