/*
** realloc_tab.c for realloc_tab.c in /home/paul.prost/Tek1/Semestre2/Prog_Elem/CPE_2016_Lemin
** 
** Made by paul prost
** Login   <paul.prost@epitech.net>
** 
** Started on  Thu Apr 27 21:55:18 2017 paul prost
** Last update Thu Apr 27 22:09:38 2017 paul prost
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
