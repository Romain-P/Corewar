/*
** my_write_reg.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar 30 18:44:25 2017 Antonin Rapini
** Last update Fri Mar 31 02:23:57 2017 Antonin Rapini
*/

#include "my_asm.h"
#include "utils.h"
#include <unistd.h>
#include <stdlib.h>

int	my_write_value(int fd, char *str, int size)
{
  char	*to_write;

  if ((to_write = malloc(sizeof(char) * size)) == NULL)
    return (1);
  my_memset(to_write, 0, size);
  my_fillstr_base(to_write, my_getnbr(str, NULL), size, HEXA_CHARSET);
  write(fd, to_write, size);
  free(to_write);
  return (0);
}
