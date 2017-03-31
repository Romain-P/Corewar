/*
** my_get_code.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Mar 29 06:43:32 2017 Antonin Rapini
** Last update Fri Mar 31 12:12:24 2017 Antonin Rapini
*/

#include "my_asm.h"
#include <stdlib.h>
#include "utils.h"
#include "sources.h"

int my_checklabel(t_labellist *to_check, t_labellist *labels)
{
  while (labels != NULL)
    {
      if (my_strcmp(to_check->label->name, labels->label->name) == 0)
	return (1);
      labels = labels->next;
    }
  return (0);
}

int		my_add_label(int i, t_cor *cor, t_labellist **startlabel)
{
  t_labellist	*currlabel;

  if ((currlabel = my_get_label(cor->file[i], cor->prog_len)) != NULL)
    {
      if (my_checklabel(currlabel, cor->labels))
	return (1);
      if (cor->labels == NULL)
	cor->labels = currlabel;
      else
	{
	  cor->labels->next = currlabel;
	  cor->labels = cor->labels->next;
	}
      cor->labels->next = NULL;
      if ((*startlabel) == NULL)
	(*startlabel) = currlabel;
    }
  return (0);
}
