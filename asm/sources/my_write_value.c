/*
** my_write_reg.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar 30 18:44:25 2017 Antonin Rapini
** Last update Fri Mar 31 09:50:52 2017 Antonin Rapini
*/

#include "my_asm.h"
#include "utils.h"
#include <unistd.h>
#include <stdlib.h>

int	my_write_value(int fd, char *str, int size)
{
  char	*to_write;
  int	nbr;
  int	i;

  i = 0;
  nbr = my_getnbr(str, NULL);
  to_write = (char *)&nbr;
  while (i < size)
    {
      write(fd, &(to_write[size - 1 - i]), 1);
      i++;
    }
  return (0);
}
