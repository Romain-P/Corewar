/*
** my_write_header.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Mar 29 21:19:05 2017 Antonin Rapini
** Last update Thu Mar 30 12:58:39 2017 Antonin Rapini
*/

#include "my_asm.h"
#include "utils.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	my_write_header(int fd, t_cor *cor)
{

  if (my_fillstr_base(cor->header->prog_len_str, cor->prog_len, PROG_LEN_LENGTH, HEXA_CHARSET))
    return (1);
  write(fd, "\0", 1);
  write(fd, COREWAR_EXEC_MAGIC_STR, my_strlen(COREWAR_EXEC_MAGIC_STR));
  write(fd, cor->header->prog_name, PROG_NAME_LENGTH);
  write(fd, cor->header->prog_len_str, PROG_LEN_LENGTH);
  write(fd, cor->header->comment, COMMENT_LENGTH);
  return (0);
}
