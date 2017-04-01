/*
** vm.h for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Mar 29 10:32:39 2017 romain pillot
** Last update Sat Apr  1 06:01:32 2017 romain pillot
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
# define HEADER_LENGTH		2192

/*
** Cycles
*/
# define CYCLE_TO_DIE		1536
# define CYCLE_DELTA		4
# define NBR_LIVE		2048

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

/*
** On process Fork:
** `data_len` contains the process instructions length,
** that should be used to get the instructions of the process
** from its starting address in the memory (cached in data_addr)
*/
typedef struct	s_process
{
  char		name[PROG_NAME_LENGTH];
  int		id;
  unsigned char	*data;
  int		data_addr;
  int		data_len;
  int		pc;
  int		cycle_cooldown;
  int		last_live_cycle;
  char		registers[REG_NUMBER][REG_SIZE];
}		t_process;

typedef struct	s_vm
{
  unsigned char	memory[MEM_SIZE];
  int		dump_cooldown;
  int		live_cooldown;
  int		cycle_to_die;
  int		current_cycle;
  int		last_die_cycle;
  bool		running;
  t_list	*processes;
}		t_vm;

t_process	*process_init(t_vm *vm, char *prog, int id, int start_pc);

void		process_kill(t_vm *vm, t_process **ptr);

void		process_insertall(t_vm *vm);

int		bytes_to_int(unsigned char a,
			     unsigned char b,
			     unsigned char c,
			     unsigned char d);

void		decode_header_name(char name[PROG_NAME_LENGTH], unsigned char *content);

bool		valid_program(unsigned char *prog_content);

void		dump_memory(char memory[MEM_SIZE]);

void		launch_cycles(t_vm *vm);

#endif /** !VM_H_ **/
