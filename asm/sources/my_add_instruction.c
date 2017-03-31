/*
** my_add_instruction.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Mar 31 11:35:56 2017 Antonin Rapini
** Last update Fri Mar 31 20:12:13 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "my_asm.h"
#include "sources.h"
#include "utils.h"

char	*my_get_instruction_name(char *line, int i)
{
  char	*name;
  int	j;

  j = 0;
  while (line[i + j] && (line[i + j] != ' ' && line[i + j] != '\t'))
    j++;
  if ((name = my_strndup(line + i, j)) == NULL)
    return (NULL);
  return (name);
}

t_instlist	*my_get_instruction(char *line, int pos)
{
  t_instlist	*item;
  t_instruct	*instruct;
  int		i;

  i = 0;
  while (line[i] && (line[i] == ' ' || line[i] == '\t'))
    i++;
  if ((instruct = malloc(sizeof(t_instruct))) == NULL)
    return (NULL);
  if ((instruct->name = my_get_instruction_name(line , i)) == NULL)
    return (NULL);
  i += my_strlen(instruct->name);
  if ((instruct->params = my_str_to_params(line + i)) == NULL)
    return (NULL);
  if (my_check_instruction(instruct))
    return (NULL);
  if ((item = malloc(sizeof(t_instlist))) == NULL)
    return (NULL);
  item->instruct = instruct;
  item->instruct->pos = pos;
  return (item);
}

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
