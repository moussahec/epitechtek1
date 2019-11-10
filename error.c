/*
** 
** Made by Moussa Hechaichi
** Login   <moussa.hechaichi@epitech.eu>
** 
** Started on  Tue Apr 25 16:45:12 2017 paul prost
** Last update Sat Apr 29 19:09:58 2017 paul prost
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
