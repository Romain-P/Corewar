/*
** my_clear_param.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar 30 18:49:09 2017 Antonin Rapini
** Last update Fri Mar 31 02:14:48 2017 Antonin Rapini
*/

#include "my_asm.h"

void	my_clear_param(t_param *param)
{
  int	i;
  int	offset;
  
  i = 0;
  offset = 1;
  if (param->islabel && param->type == T_DIR)
    offset = 2;
  while (param->param[i + offset])
    {
      param->param[i] = param->param[i + offset];
      i++;
    }
  param->param[i] = '\0';
}
