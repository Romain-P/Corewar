/*
** op_live.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src/mnemonic
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun Apr  2 03:16:05 2017 romain pillot
** Last update Sun Apr  2 20:58:15 2017 romain pillot
*/

#include "operation.h"
#include "util.h"

void	op_aff(t_vm *vm, t_process *process, t_param params[4])
{
  int	reg;
  int	value;

  reg = parse_value(params[0], vm, process, NO_MOD);
  if (reg > 16 || reg <= 0)
    return ;
  value = process->registers[reg - 1];
  display_char(value % 256, false);
}
