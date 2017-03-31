/*
** sources.h for base in /home/antonin.rapini/my_programs/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar  2 17:18:06 2017 Antonin Rapini
** Last update Fri Mar 31 12:11:35 2017 Antonin Rapini
*/

#ifndef SOURCES_H_
# define SOURCES_H_

#include "my_asm.h"

t_cor *my_get_champion(char *);
int my_get_header(char **, t_header *);
int my_get_code(int, t_cor *);
t_labellist *my_get_label(char *, int);
t_instlist *my_get_instruction(char *, int);
int my_instructionlen(t_instruct *);
char my_get_paramtype(t_param *);
int my_check_instruction(t_instruct *);
int my_create_corfile(t_cor *, char *);
int my_write_header(int, t_cor *);
int my_write_instructions(int, t_cor *);
int my_write_params(int, t_param *, t_labellist *, int);
int my_write_value(int, char *, int);
void my_clear_param(t_param *);
int my_add_label(int , t_cor *, t_labellist **);
int my_add_instruction(int, t_cor *, t_instlist **);

#endif /* !SOURCES_H_ */
