/*
** op.c for  korewar
**
** Made by Astek
** Login   <astek@epitech.net>
**
** Started on  Mon Mar 30 11:14:31 2009 Astek
** Last update Wed Mar 29 15:31:45 2017 Antonin Rapini
*/

#include "my_asm.h"

static t_op const (const op_tab[]) =
  {
    {"live", 1, {T_DIR}, 1, 10, "alive"},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2},
    {"st", 2, {T_REG, T_IND | T_REG}, 3},
    {"add", 3, {T_REG, T_REG, T_REG}, 4},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8},
    {"zjmp", 1, {T_DIR}, 9},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11},
    {"fork", 1, {T_DIR}, 12},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14},
    {"lfork", 1, {T_DIR}, 15},
    {"aff", 1, {T_REG}, 16},
    {0, 0, {0}, 0}
  };
