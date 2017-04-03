/*
** op_live.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src/mnemonic
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun Apr  2 03:16:05 2017 romain pillot
** Last update Sun Apr  2 21:05:19 2017 romain pillot
*/

#include "operation.h"
#include <stdlib.h>
#include "util.h"

void		op_live(t_vm *vm, t_process *process, t_param params[4])
{
  int		value;
  int		i;
  t_elem	*curr;

  curr = vm->processes->first;
  i = 0;
  value = parse_value(params[0], vm, process, NO_MOD);
  while (curr != NULL)
    {
      if (value == ((t_process *) curr->get)->id)
	{
	  ((t_process *) curr->get)->last_live_cycle = vm->current_cycle;
	  display_format("The player %d(%s) is alive.\n",
			 process->id, process->name);
	  return ;
	}
      curr = curr->next;
    }
}
