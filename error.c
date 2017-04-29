/*
** error.c for error.c in /home/paul.prost/Tek1/Semestre2/Prog_Elem/CPE_2016_Lemin
** 
** Made by paul prost
** Login   <paul.prost@epitech.net>
** 
** Started on  Sat Apr 29 17:08:26 2017 paul prost
** Last update Sat Apr 29 20:22:19 2017 paul prost
*/

#include "my.h"

int     check_words(char *str, t_data *d)
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

int	check_error(t_list *link, char *name)
{
  t_node        *node;
  t_elem        *elem;

  elem = link->first;
  if (elem == NULL)
    return (0);
  while (elem != NULL)
    {
      node = elem->data;
      if (my_strcmp(node->name, name) == 1)
	return (84);
      elem = elem->next;
    }
  return (0);
}
