/*
** my_getoctal.c for my_tar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_b2rush1/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Mar  5 15:16:02 2017 Antonin Rapini
** Last update Sun Mar  5 16:04:01 2017 Antonin Rapini
*/

int	my_getoctal(char *str)
{
  int	i;
  int	number;

  number = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] - 48 <= 7)
	number = number * 8 + (str[i] - 48);
      else
	return (0);
      i++;
    }
  return (number);
}
