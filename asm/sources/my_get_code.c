/*
** my_get_code.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Mar 29 06:43:32 2017 Antonin Rapini
** Last update Fri Mar 31 10:59:57 2017 Antonin Rapini
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

int			my_get_code(int i, t_cor *cor)
{
  t_labellist		*startlabel;
  t_labellist		*currlabel;
  t_instlist		*currinst;
  t_instlist		*startinst;

  while (cor->file[i])
    {
      if (is_codeline(cor->file[i]))
	{
	  if ((currlabel = my_get_label(cor->file[i], cor->prog_len)) != NULL)
	    {
	      if (cor->labels == NULL)
		{
		  cor->labels = currlabel;
		  startlabel = currlabel;
		}
	      else
		cor->labels = cor->labels->next = currlabel;
	    }
	  if ((currinst = my_get_instruction(cor->file[i], cor->prog_len)) == NULL)
	    return (1);
	  if (cor->instructs == NULL)
	    {
	      cor->instructs = currinst;
	      cor->instructs->next = NULL;
	      startinst = currinst;
	    }
	  else
	    cor->instructs = cor->instructs->next = currinst;
	  cor->prog_len += my_instructionlen(cor->instructs->instruct);
	}
      i++;
    }
  cor->instructs = startinst;
  cor->labels = startlabel;
  return (0);
}
