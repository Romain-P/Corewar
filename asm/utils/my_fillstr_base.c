/*
** my_filloctal.c for my_tar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_b2rush1/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Mar  5 15:16:58 2017 Antonin Rapini
** Last update Thu Mar 30 13:00:53 2017 Antonin Rapini
*/

#include "utils.h"
#include <stdlib.h>

int	my_fillstr_base(char *str, int nbr, int maxsize, char *base)
{
  int	div;
  int	base_size;
  int	i;
  int	size;
  char	*tmp;

  base_size = my_strlen(base);
  if ((tmp = malloc(sizeof(char) * (maxsize + 1))) == NULL)
    return (1);
  i = 0;
  div = 1;
  while (nbr / div >= base_size)
    div = div * base_size;
  while (div >= 1)
    {
      tmp[i] = nbr / div;
      nbr = nbr % div;
      div = div / base_size;
      i++;
    }
  tmp[i] = '\0';
  size = my_strlen(tmp);
  i = 0;
  while (i++ < size)
      str[i + maxsize - size - 1] = tmp[i - 1];
  free(tmp);
  return (0);
}
