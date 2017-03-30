/*
** my_get_label.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Mar 29 06:47:03 2017 Antonin Rapini
** Last update Wed Mar 29 19:13:06 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "utils.h"
#include "my_asm.h"

void	my_remove_label(char *line, int offset)
{
  int	i;

  i = 0;
  while (line[i + offset])
    {
      line[i] = line[i + offset];
      i++;
    }
  line[i] = '\0';
}

int	is_label_char(char c)
{
  int	i;

  i = 0;
  while (LABEL_CHARS[i])
    {
      if (c == LABEL_CHARS[i])
	return (1);
      i++;
    }
  return (0);
}

t_labellist	*my_get_label(char *line, int labelpos)
{
  t_labellist	*item;
  char		*name;
  int		i;
  int		j;

  i = 0;
  while (line[i] && (line[i] == ' ' || line [i] == '\t'))
    i++;
  j = i;
  while (is_label_char(line[j]))
    j++;
  if (line[j] != ':')
    return (NULL);
  if ((name = my_strndup(line + i, j - i)) == NULL)
    return (NULL);
  if ((item = malloc(sizeof(t_labellist))) == NULL)
    return (NULL);
  if ((item->label = malloc(sizeof(t_label))) == NULL)
    return (NULL);
  item->label->name = name;
  item->label->pos = labelpos;
  my_remove_label(line, j + 1);
  return (item);
}
