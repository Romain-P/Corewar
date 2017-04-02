/*
** op_live.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src/mnemonic
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun Apr  2 03:16:05 2017 romain pillot
** Last update Sun Apr  2 17:00:06 2017 Antonin Rapini
*/

#include "operation.h"

void	op_and(t_vm *vm, t_process *process, t_param params[4])
{
  int	value1;
  int	value2;
  int	reg;

  value1 = parse_value(param[0], NO_MOD);
  value2 = parse_value(param[1], NO_MOD);
  reg = parse_value(param[2], NO_MOD);
  if (reg > 16 || reg <= 0)
    {
      process->carry = 0;
      return ;
    }
  process->registers[reg - 1] = value1 & value2;
  process->carry = 1;
}
