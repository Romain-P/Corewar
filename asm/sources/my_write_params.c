/*
** my_write_params.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar 30 18:35:34 2017 Antonin Rapini
** Last update Fri Mar 31 11:55:36 2017 Antonin Rapini
*/

#include "my_asm.h"
#include "sources.h"

int	my_write_param(int fd, t_param *param, t_labellist *labels, int isindex)
{
  int	param_size;

  param_size = param->type == 1 ? 1 : param->type == 4 || isindex ? 2 : 4;
  if (!param->islabel)
    return (my_write_value(fd, param->param, param_size));
  if (labels)
    {
    }
  return (0);
}

int	my_write_params
(int fd, t_param *params, t_labellist *labels, int isindex)
{
  int	i;

  i = 0;
  while (params[i].param)
    {
      if (my_write_param(fd, &(params[i]), labels, isindex))
	return (1);
      i++;
    }
  return (0);
}
