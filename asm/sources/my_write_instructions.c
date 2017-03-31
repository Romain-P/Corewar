/*
** my_write_instructions.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar 30 17:34:13 2017 Antonin Rapini
** Last update Fri Mar 31 11:56:36 2017 Antonin Rapini
*/

#include "sources.h"
#include "my_asm.h"
#include "utils.h"
#include <unistd.h>
#include <stdlib.h>

void	my_write_instructinfos(int fd, int code, int codingbyte)
{
  char	strcode[1];

  strcode[0] = code;
  write(fd, strcode, 1);
  if (codingbyte != -1)
    {
      strcode[0] = codingbyte;
      write(fd, strcode, 1);
    }
}

int my_write_instruct
(int fd, t_labellist *labels, t_instruct *instruct, int isindex)
{
  my_write_instructinfos(fd, instruct->code, instruct->codingbyte);
  if (my_write_params(fd, instruct->params, labels, isindex))
    return (1);
  return (0);
}

int	my_write_instructions(int fd, t_cor *cor)
{
  int	code;

  while (cor->instructs != NULL)
    {
      code = cor->instructs->instruct->code;
      if (my_write_instruct(fd, cor->labels, cor->instructs->instruct,
			    (code >= 9 && code <= 15) && code != 13))
	return (1);
      cor->instructs = cor->instructs->next;
    }
  return (0);
}
