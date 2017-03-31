/*
** my_get_code.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Mar 29 06:43:32 2017 Antonin Rapini
** Last update Fri Mar 31 12:12:49 2017 Antonin Rapini
*/

#include "my_asm.h"
#include <stdlib.h>
#include "utils.h"
#include "sources.h"

int	is_codeline(char *line)
{
  int	i;

  i = 0;
  while (line[i])
    {
      if (line[i] != ' ' && line[i] != '\t')
	return (1);
      i++;
    }
  return (0);
}

int		my_get_code(int i, t_cor *cor)
{
  t_labellist	*startlabel;
  t_instlist	*startinst;

  startlabel = NULL;
  startinst = NULL;
  while (cor->file[i])
    {
      if (is_codeline(cor->file[i]))
	{
	  if (my_add_label(i, cor, &startlabel))
	    return (1);
	  if (my_add_instruction(i, cor, &startinst))
	    return (1);
	}
      i++;
    }
  cor->instructs = startinst;
  cor->labels = startlabel;
  return (0);
}
