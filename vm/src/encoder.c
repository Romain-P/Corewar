/*
** encoder.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Mar 30 14:06:31 2017 romain pillot
** Last update Sat Apr  1 00:50:47 2017 romain pillot
*/

#include "vm.h"
#include <stdbool.h>

int	bytes_to_int(unsigned char a,
		     unsigned char b,
		     unsigned char c,
		     unsigned char d)
{
  return ((a << 24) + (b << 16) + (c << 8) + d);
}

bool	valid_program(unsigned char *bytes)
{
  return (bytes_to_int(bytes[0], bytes[1], bytes[2], bytes[3])
	  == COREWAR_EXEC_MAGIC);
}

void	decode_header_name(char name[PROG_NAME_LENGTH], unsigned char *content)
{
  int	i;

  i = -1;
  while (++i < PROG_NAME_LENGTH && content[i + MAGIC_LENGTH])
    name[i] = content[i + MAGIC_LENGTH];
  name[i] = 0;
}
