/*
** my_get_header.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Mar 28 06:44:39 2017 Antonin Rapini
** Last update Wed Mar 29 06:03:18 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "utils.h"
#include "my_asm.h"

int     fill_header(char *buffer, char *prog_name, char *id, int maxsize)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (buffer[i++] == ' ');
  if (my_strncmp(buffer + i - 1, id, my_strlen(id)) != 0)
    return (1);
  i += my_strlen(id) - 1;
  while (buffer[i++] == ' ');
  if (buffer[i - 1] != '"')
    return (2);
  while (buffer[i] && buffer[i] != '"')
    {
      if (j >= maxsize)
	return (2);
      prog_name[j] = buffer[i];
      j++;
      i++;
    }
  if (!buffer[i])
    return (2);
  while (buffer[++i])
    if (buffer[i - 1] != ' ' && buffer[i - 1] != COMMENT_CHAR)
      return (2);
  return (0);
}

int	my_get_header(char **file, t_header *header)
{
  int	status;
  int	ret;
  int	i;

  i = 0;
  status = 0;
  while (status != 2 && file[i])
    {
      if (file[i][0] != '\0' && file[i][0] != COMMENT_CHAR)
	{
	  ret = status == 0 ?
	    fill_header(file[i], header->prog_name, ".name", PROG_NAME_LENGTH) :
	    fill_header(file[i], header->comment, ".comment", COMMENT_LENGTH);
	  if ((ret != 0 && status == 0) || (ret == 2 && status == 1))
	    return (-1);
	  if (ret == 1 && status == 1)
	    return (i);
	  status++;
	}
      i++;
    }
  return (i);
}
