/*
** file.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Mar 30 14:03:00 2017 romain pillot
** Last update Fri Mar 31 13:17:05 2017 romain pillot
*/

#include "util.h"
#include "file.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char		*file_content(int file)
{
  char		*content;
  char		buffer[1024 + 1];
  int		bytes;
  int		len;

  content = NULL;
  len = 0;
  while ((bytes = read(file, buffer, 1024)))
    {
      if (bytes == -1)
	break;
      buffer[bytes] = 0;
            content = content ?
	      copystr(malloc(sizeof(char) * (len += bytes)), buffer, 0) :
	      copystr(realloc(content, sizeof(char) * (len += bytes)), buffer, len - bytes);
    }
  if (bytes == -1 && content)
    free(content);
  return (content);
}

int		open_file(char *file_name)
{
  int		file;

  if ((file = open(file_name, O_RDONLY)) == -1)
    fdisplay_format("%s: can't open the file\n", file_name);
  return (file);
}
