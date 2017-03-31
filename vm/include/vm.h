/*
** vm.h for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Mar 29 10:32:39 2017 romain pillot
** Last update Thu Mar 30 15:26:02 2017 romain pillot
*/

#ifndef VM_H_
# define VM_H_

# include <stdbool.h>
# include "list.h"

/*
** Magic code
*/
# define COREWAR_EXEC_MAGIC	0xea83f3 

/*
** OP argument types
*/
# define T_REG			1
# define T_DIR			2
# define T_IND			4
# define T_LAB			8

/*
** Number of registers per processus
*/
# define REG_NUMBER		16

/*
** Multiples sizes
*/
# define IND_SIZE		2
# define DIR_SIZE		4
# define REG_SIZE		DIR_SIZE

/*
** Header infos
*/
# define PROG_NAME_LENGTH	128
# define COMMENT_LENGTH		2048
# define MAGIC_LENGTH		4
# define LEN_LENGTH		8
# define HEADER_LENGTH		(128 + 2048 + 4 + 8)

/*
** Cycles
*/
# define CYCLE_TO_DIE		1536
# define CYCLE_DELTA		5
# define NBR_LIVE		40

/*
** Memory
*/
# define MEM_SIZE		(6*1024)
# define IDX_MOD		512
# define MAX_ARGS_NUMBER	4

typedef struct	op_s
{
  char		*mnemonique;
  char		ac;
  char		type[MAX_ARGS_NUMBER];
  char		code;
  int		cycles;
  char		*comment;
}		op_t;

typedef struct	s_process
{
  char		*name;
  int		id;
  char		*instructions;
  int		waiting_cycles;
  char		registers[REG_NUMBER][REG_SIZE];
}		t_process;

typedef struct	s_vm
{
  char		memory[MEM_SIZE];
  int		dump_cycles;
  t_list	*processes;
}		t_vm;

t_process	*process_init(t_vm *vm, char *prog, int id, int start_pc);

void		process_kill(t_vm *vm, t_process **ptr);

char		*decode_header_name(char *prog_content);

bool		valid_program(char *prog_content);

#endif /** !VM_H_ **/
