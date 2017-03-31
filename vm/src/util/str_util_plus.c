/*
** str_util_plus.c for  in /home/romain.pillot/projects/PSU_2016_tetris/src/util
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Mar 15 09:14:24 2017 romain pillot
** Last update Thu Mar 30 14:57:42 2017 romain pillot
*/

#include "util.h"
#include <stdlib.h>

char    *fillstr(char *str, char c, int bytes)
{
  int   i;

  if (!str)
    return (NULL);
  i = -1;
  while (++i < bytes)
    str[i] = c;
  return (str);
}

char	*get_filename(char *str)
{
  int	i;

  i = str_length(str);
  while (str[--i])
    if (str[i] == '.')
      str[i] = 0;
  return (str);
}

char	*copystr(char *from, char *to, int index)
{
  int	len;

  if (!from || !to || index < 0)
    return (NULL);
  while (*from)
    to[index++] = *from++;
  to[index] = 0;
  return (to);
}
