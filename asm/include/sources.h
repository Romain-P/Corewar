/*
** sources.h for base in /home/antonin.rapini/my_programs/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar  2 17:18:06 2017 Antonin Rapini
** Last update Wed Mar 29 21:24:35 2017 Antonin Rapini
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

#endif /* !SOURCES_H_ */
