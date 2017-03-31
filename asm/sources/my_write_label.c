/*
** my_write_label.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Mar 31 12:40:01 2017 Antonin Rapini
** Last update Fri Mar 31 14:02:52 2017 Antonin Rapini
*/

#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "my_asm.h"

int my_write_label(int fd, t_param *param, t_labellist *labels, int pos)
{
  if (fd && pos)
    {
    }
  while (labels != NULL)
    {
      if (my_strcmp(param->param, labels->label->name) == 0)
	{
	  return (0);
	}
      labels = labels->next;
    }
  return (1);
}
