/*
** file.h for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Mar 30 14:01:15 2017 romain pillot
** Last update Thu Mar 30 14:48:23 2017 romain pillot
*/

#ifndef FILE_H_
# define FILE_H_

int	open_file(char *file_name);

char	*file_content(int file_descriptor);

#endif /* !FILE_H_ */
