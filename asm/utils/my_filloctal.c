/*
** my_filloctal.c for my_tar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_b2rush1/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Mar  5 15:16:58 2017 Antonin Rapini
** Last update Thu Mar 30 10:13:44 2017 Antonin Rapini
*/

#include "utils.h"
#include <stdlib.h>

void	my_filloctal(char *str, int nbr, int maxsize)
{
  int	div;
  int	i;
  int	size;
  char	*tmp;

  if ((tmp = malloc(sizeof(char) * (maxsize + 1))) == NULL)
    return ;
  i = 0;
  div = 1;
  while (nbr / div >= 8)
    div = div * 8;
  while (div >= 1)
    {
      tmp[i] = nbr / div + '0';
      nbr = nbr % div;
      div = div / 8;
      i++;
    }
  tmp[i] = '\0';
  size = my_strlen(tmp);
  i = 0;
  while (i++ < size)
      str[i + maxsize - size - 2] = tmp[i - 1];
  free(tmp);
}
