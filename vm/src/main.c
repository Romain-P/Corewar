/*
** main.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Mar 29 10:33:03 2017 romain pillot
** Last update Fri Mar 31 13:21:07 2017 romain pillot
*/

#include <stdlib.h>
#include <getopt.h>
#include "vm.h"
#include "option.h"
#include "util.h"

static int	free_and_exit(t_vm **to_free, int statement, char *err)
{
  if (err)
    display(err, true);
  if (*to_free)
    free(*to_free);
  *to_free = NULL;
  return (statement);
}

static t_vm	*vm_init()
{
  t_vm		*vm;
  int		i;

  i = -1;
  if (!(vm = malloc(sizeof(t_vm))))
    return (NULL);
  vm->processes = list_create();
  vm->dump_cycles = -1;
  while (++i < MEM_SIZE)
    vm->memory[i] = 0;
  return (vm);
}

int	main(int ac, char **args)
{
  t_vm	*vm;

  if (!(vm = vm_init()) || !valid_options(vm, ac, args))
    return (free_and_exit(&vm, 84, NULL));
  if (vm->processes->size < 2 || vm ->processes->size > 4)
    return (free_and_exit(&vm, 84,
			  "Error: need at least 2 programs and at most 4 programs.\n"));
  return (free_and_exit(&vm, EXIT_SUCCESS, NULL));
}
