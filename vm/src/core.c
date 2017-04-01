/*
** core.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sat Apr  1 03:46:54 2017 romain pillot
** Last update Sat Apr  1 07:16:19 2017 romain pillot
*/

#include "vm.h"
#include "util.h"
#include <stdbool.h>
#include <stdlib.h>

static void	on_cycle(t_vm *vm, void **proc_ptr, int cycle, int last_die_cycle)
{
  t_process	*proc;

  proc = (t_process *) (*proc_ptr);
  if (vm->current_cycle - vm->last_die_cycle == vm->cycle_to_die &&
      proc->last_live_cycle <= last_die_cycle)
    return (process_kill(vm, (t_process **) proc_ptr));
  //TODO: read next instruction
}

static void	check_end(t_vm *vm)
{
  t_elem	*elem;
  t_elem	*previous;

  previous = NULL;
  if (!(elem = vm->processes->first))
    {
      display("There is no winner.\n", false);
      vm->running = false;
      return ;
    }
  while (elem)
    {
      if (previous &&
	  ((t_process *) previous->get)->id != ((t_process *) elem->get)->id)
	return ;
      previous = elem;
      elem = elem->next;
    }
  display_format("The player %d(%s) has won",
		 ((t_process *) previous->get)->id,
		 ((t_process *) previous->get)->name);
}

void		launch_cycles(t_vm *vm)
{
  t_elem	*elem;
  t_elem	*next;

  process_insertall(vm);
  while (vm->running && ++(vm->current_cycle))
    {
      elem = vm->processes->first;
      while (elem)
	{
	  next = elem->next;
	  on_cycle(vm, &elem->get, vm->current_cycle, vm->last_die_cycle);
	  elem = next;
	}
      if ((vm->live_cooldown) <= 0)
	{
	  vm->cycle_to_die -= CYCLE_DELTA;
	  vm->live_cooldown = NBR_LIVE;
	}
      if (vm->current_cycle - vm->last_die_cycle == vm->cycle_to_die)
	vm->last_die_cycle = vm->current_cycle;
      check_end(vm);
    }
}
