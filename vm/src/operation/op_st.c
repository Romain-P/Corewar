/*
** op_live.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src/mnemonic
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun Apr  2 03:16:05 2017 romain pillot
** Last update Sun Apr  2 17:10:13 2017 Antonin Rapini
*/

#include "operation.h"

void	op_st(t_vm *vm, t_process *process, t_param params[4])
{
  int	reg;
  int	reg2;
  int	adress;

  reg = parse_value(params[0], vm, process, NO_MOD);
  if (reg > 16 || reg <= 0)
    return ;
  if (params[i].type = T_REG)
    {
      reg2 = parse_value(params[1], vm, process, NO_MOD);
      if (reg2 > 16 || reg2 <= 0)
	return ;
      process->registers[reg2 - 1] = process->registers[reg - 1];
    }
  else
    vm->memory[process->pc + params[i].value] = process->registers[reg - 1];
}
