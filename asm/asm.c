/*
** asm.c for asm in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Mar 27 14:24:49 2017 Antonin Rapini
** Last update Wed Mar 29 20:58:39 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "my_asm.h"
#include "sources.h"

int		main(int ac, char **av)
{
  t_cor		*cor;

  if (ac >= 2)
    {
      if ((cor = my_get_champion(av[1])) == NULL)
	return (84);
      if (my_create_corfile(cor, av[1]))
	return (84);
      return (0);
    }
  return (84);
}
