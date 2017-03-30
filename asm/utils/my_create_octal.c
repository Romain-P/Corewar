/*
** my_create_octal.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar 30 10:11:06 2017 Antonin Rapini
** Last update Thu Mar 30 10:29:25 2017 Antonin Rapini
*/

#include "utils.h"
#include <stdlib.h>

char	*my_create_octal(int nbr)
{
  int	div;
  int	i;
  char	*str;

  if ((str = malloc(sizeof(char) * (my_nbrlen(nbr) + 1))) == NULL)
    return (NULL);
  i = 0;
  div = 1;
  while (nbr / div >= 8)
    div = div * 8;
  while (div >= 1)
    {
      str[i] = nbr / div;
      nbr = nbr % div;
      div = div / 8;
      i++;
    }
  str[i] = '\0';
  return (str);
  i = 0;
}
