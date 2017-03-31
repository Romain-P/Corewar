/*
** my_add_instruction.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Mar 31 11:35:56 2017 Antonin Rapini
** Last update Fri Mar 31 12:12:01 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "my_asm.h"
#include "sources.h"

int		my_add_instruction(int i, t_cor *cor, t_instlist **startinst)
{
  t_instlist	*currinst;

  if ((currinst = my_get_instruction(cor->file[i], cor->prog_len)) == NULL)
    return (1);
  if (cor->instructs == NULL)
    cor->instructs = currinst;
  else
    {
      cor->instructs->next = currinst;
      cor->instructs = cor->instructs->next;
    }
  cor->instructs->next = NULL;
  if ((*startinst) == NULL)
    (*startinst) = currinst;
  cor->prog_len += my_instructionlen(cor->instructs->instruct);
  return (0);
}
