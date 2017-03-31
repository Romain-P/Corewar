/*
** my_write_reg.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar 30 18:44:25 2017 Antonin Rapini
** Last update Fri Mar 31 10:17:05 2017 Antonin Rapini
*/

#include "my_asm.h"
#include "utils.h"
#include <unistd.h>
#include <stdlib.h>

int	my_write_value(int fd, char *str, int size)
{
  char	*bytes;
  char	*to_write;
  int	nbr;
  int	i;

  if ((to_write = malloc(sizeof(char) * size)) == NULL)
    return (1);
  my_memset(to_write, 0, size);
  i = 0;
  nbr = my_getnbr(str, NULL);
  bytes = (char *)&nbr;
  while (i < size)
    {
      to_write[i] = bytes[size - 1 - i];
      i++;
    }
  write(fd, to_write, size);
  free(to_write);
  return (0);
}
