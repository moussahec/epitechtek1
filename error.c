/*
** error.c for error.c in /home/paul.prost/Tek1/Semestre2/Prog_Elem/CPE_2016_Lemin
** 
** Made by paul prost
** Login   <paul.prost@epitech.net>
** 
** Started on  Sat Apr 29 17:08:26 2017 paul prost
** Last update Sun Apr 30 22:31:58 2017 paul prost
*/

#include "my.h"

int	check_words(char *str, t_data *d)
{
  char	**tab;
  int   len;
  int	i;

  i = 0;
  len = 0;
  tab = str_to_wordtab(str, d);
  while (tab[i])
    {
      if (tab[i][0] != '#')
	len++;
      i++;
    }
  return (len);
}

int	tunnels_error(char *str)
{
  int	i;
  int	n;

  n = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] == '-')
	n++;
      i++;
    }
  if (n != 1)
    return (84);
  return (0);
}
