/*
** core.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sat Apr  1 03:46:54 2017 romain pillot
** Last update Sun Apr  2 15:09:09 2017 romain pillot
*/

#include "vm.h"
#include "util.h"
#include <stdbool.h>
#include <stdlib.h>

static void	on_cycle(t_vm *vm, void **proc_ptr)
{
  t_process	*proc;
  t_op		*op;
  t_param	params[4];
  int		param_bytes;

  proc = (t_process *) (*proc_ptr);
  printf("%d-", proc->pc);
  unsigned char c = vm->memory[proc->pc % MEM_SIZE];
  if (vm->current_cycle - vm->last_die_cycle == vm->cycle_to_die &&
      proc->last_live_cycle <= vm->last_die_cycle)
    return (process_kill(vm, (t_process **) proc_ptr));
  else if ((op = parse_operation(vm->memory[proc->pc % MEM_SIZE]))->code != OP_NULL &&
	   (param_bytes = parse_params(proc, vm->memory, op, params)))
    {
      op->execute(vm, proc, params);
      display("done", false);
      if (op->code != OP_ZJMP)
	proc->pc += param_bytes;
    }
  else
    proc->pc++;
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
  display_format("The player %d(%s) has won.",
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
	  on_cycle(vm, &(elem->get));
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
