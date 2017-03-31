/*
** my_get_code.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Mar 29 06:43:32 2017 Antonin Rapini
** Last update Fri Mar 31 15:45:08 2017 Antonin Rapini
*/

#include "my_asm.h"
#include <stdlib.h>
#include "utils.h"
#include "sources.h"

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

int my_checklabel(t_labellist *to_check, t_labellist *labels)
{
  while (labels != NULL)
    {
      if (my_strcmp(to_check->label->name, labels->label->name) == 0)
	return (1);
      labels = labels->next;
    }
  return (0);
}

int		my_add_label(int i, t_cor *cor, t_labellist **startlabel)
{
  t_labellist	*currlabel;

  if ((currlabel = my_get_label(cor->file[i], cor->prog_len)) != NULL)
    {
      if (my_checklabel(currlabel, cor->labels))
	return (1);
      if (cor->labels == NULL)
	cor->labels = currlabel;
      else
	{
	  cor->labels->next = currlabel;
	  cor->labels = cor->labels->next;
	}
      cor->labels->next = NULL;
      if ((*startlabel) == NULL)
	(*startlabel) = currlabel;
    }
  return (0);
}

