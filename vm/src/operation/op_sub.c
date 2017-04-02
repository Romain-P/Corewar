/*
** op_live.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src/mnemonic
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun Apr  2 03:16:05 2017 romain pillot
** Last update Sun Apr  2 21:18:38 2017 romain pillot
*/

#include "operation.h"

void	op_sub(t_vm *vm, t_process *process, t_param params[4])
{
  int	registera;
  int	registerb;
  int	registerc;

  registera = parse_value(params[0], vm, process, NO_MOD);
  registerb = parse_value(params[1], vm, process, NO_MOD);
  registerc = parse_value(params[2], vm, process, NO_MOD);
  if (registera > 16 || registerb > 16 || registerc > 16 || registera <= 0
      || registerb <= 0 || registerc <= 0)
    {
      return ;
    }
  process->registers[registerc - 1] = process->registers[registera - 1] +
    process->registers[registerb - 1];
}
