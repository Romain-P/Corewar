/*
** op_live.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src/mnemonic
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun Apr  2 03:16:05 2017 romain pillot
** Last update Sun Apr  2 21:17:20 2017 romain pillot
*/

#include "operation.h"

void	op_ldi(t_vm *vm, t_process *process, t_param params[4])
{
  int	value1;
  int	value2;
  int	reg;
  int	finaladress;
  int	finalvalue;

  reg = parse_value(params[2], vm, process, NO_MOD);
  if (reg > 16 || reg <= 0)
    {
      return ;
    }
  value1 = parse_value(params[0], vm, process, MOD | IND);
  value2 = parse_value(params[1], vm, process, NO_MOD);
  finaladress = value1 + value2;
}
