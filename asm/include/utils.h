/*
** utils.h for base in /home/antonin.rapini/my_programs/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar  2 17:18:39 2017 Antonin Rapini
** Last update Fri Mar 31 11:54:42 2017 Antonin Rapini
*/

#ifndef UTILS_H_
# define UTILS_H_

# define READ_SIZE 256

#include "my_asm.h"

char *get_next_line(int);
int my_strlen(char *);
int my_strcmp(char *, char *);
void my_memset(void *, char, int);
t_cor *my_init_cor();
void *my_free_cor(t_cor *cor);
int my_open_champion(char *);
int my_strncmp(char *, char *, int);
void my_free_wordtab(char **);
char **my_getfile(char *);
void my_putchar(char);
void my_putstr(char *);
void my_show_wordtab(char **);
char *my_strndup(char *, int);
int my_getnbr(char *, int *);
t_param *my_str_to_params(char *);
int my_miniprintf(char *, ...);
void my_put_nbr(int);
char *my_int_tostr(int);
int my_nbrlen(int);

#endif /* !UTILS_H_ */
