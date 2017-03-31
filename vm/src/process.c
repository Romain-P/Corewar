/*
** process.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Mar 30 12:48:47 2017 romain pillot
** Last update Thu Mar 30 16:27:06 2017 romain pillot
*/

#include "vm.h"
#include "util.h"
#include "list.h"
#include <unistd.h>
#include <stdlib.h>
#include "file.h"

static int	next_process_id(t_list *list, int id)
{
  t_elem	*elem;

  id = id == -1 ? list->size + 1 : id;
  elem = list->first;
  while (elem)
    {
      if (((t_process *) elem->get)->id == id)
	return (next_process_id(list, ++id));
      elem = elem->next;
    }
  return (id);
}

t_process       *process_init(t_vm *vm, char *prog, int id, int start_pc)
{
  t_process	*process;
  int		file;
  char		*content;

  if ((file = open_file(prog)) == -1 ||
      !(content = file_content(file)) ||
      !(process = malloc(sizeof(t_process))))
    return (NULL);
  if (!valid_program(content) || !id || !start_pc)
    {
      fdisplay_format(!id || !start_pc ?
		      "%s: invalid program (invalid magic)\n" :
		      "%s: invalid parameters ((int)param > 0)\n", prog);
      free(process);
      return (NULL);
    }
  process->name = decode_header_name(content);
  process->id = next_process_id(vm->processes, id);
  process->instructions = strdupl(content + HEADER_LENGTH);
  list_add(vm->processes, process);
  free(content);
  close(file);
  return (process);
}
