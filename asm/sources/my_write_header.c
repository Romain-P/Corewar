/*
** my_write_header.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Mar 29 21:19:05 2017 Antonin Rapini
** Last update Thu Mar 30 10:26:10 2017 Antonin Rapini
*/

#include "my_asm.h"
#include "utils.h"
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

int	my_write_header(int fd, t_cor *cor)
{
  char	*prog_len;

  if ((prog_len = my_create_octal(cor->prog_len)) == NULL)
    return (1);
  write(fd, "\0", 1);
  write(fd, COREWAR_EXEC_MAGIC_STR, my_strlen(COREWAR_EXEC_MAGIC_STR));
  write(fd, cor->header->prog_name, PROG_NAME_LENGTH);
  write(fd, prog_len, my_strlen(prog_len));
  write(fd, cor->header->comment, COMMENT_LENGTH);
  free(prog_len);
  return (0);
}
