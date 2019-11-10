/*
** 
** Made by Moussa Hechaichi
** Login   <moussa.hechaichi@epitech.eu>
** 
** Started on  Tue Apr 25 16:45:12 2017 paul prost
** Last update Sat Apr 29 19:09:58 2017 paul prost
*/

#include "my.h"

void	realloc_tab(char *s, t_data *d)
{
  int	len;
  char	**tab;
  int	i;

  i = 0;
  len = 0;
  while (d->tunnels[len] != NULL)
    len++;
  len++;
  tab = malloc(sizeof(char *) * (len + 1));
  tab[len] = NULL;
  while (d->tunnels[i] != NULL)
    {
      tab[i] = d->tunnels[i];
      i++;
    }
  tab[i] = s;
  d->tunnels = tab;
}
