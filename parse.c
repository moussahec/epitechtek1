/*
** parse.c for parse.c in /home/paul.prost/Tek1/Semestre2/Prog_Elem/CPE_2016_Lemin
** 
** Made by paul prost
** Login   <paul.prost@epitech.net>
** 
** Started on  Wed Apr 26 11:05:20 2017 paul prost
** Last update Thu Apr 27 17:11:26 2017 paul prost
*/

#include "my.h"

int	handle_command(int fd, char *s, t_data *d, t_list *list)
{
  if (my_strcmp(s, "##start"))
    {
      while (s[0] == '#')
	s = get_next_line(fd);
      create_room(s, 1, d, list);
    }
  else if (my_strcmp(s, "##end"))
    {
      while (s[0] == '#')
	s = get_next_line(fd);
      create_room(s, 2, d, list);
    }
  return (fd);
}

void		create_room(char *s, int a, t_data *d, t_list *list)
{
  char		**tab;
  t_node	*node;

  list = list;
  tab = my_str_to_wordtab(s, 3, ' ');
  if (a == 1)
    {
      d->start = tab[0];
      d->start_posx = my_get_nbr(tab[2]);
      d->start_posy = my_get_nbr(tab[1]);
    }
  else if (a == 2)
    {
      d->end = tab[0];
      d->end_posx = my_get_nbr(tab[2]);
      d->end_posy = my_get_nbr(tab[1]);
    }
  node = create_nodes(tab[0], my_get_nbr(tab[1]), my_get_nbr(tab[2]));
  push_back(list, node);
  free(tab);
}

void	create_tunnels(char *s)
{
  char	**tab;

  tab = my_str_to_wordtab(s, 2, '-');
}

int	anth_nbr(int fd, t_data *d)
{
  char	*s;

  if ((s = get_next_line(fd)) == NULL)
    return (-1);
  while (s[0] == '#')
    s = get_next_line(fd);
  if (check_num(s) == 0)
    d->anth_nbr = my_get_nbr(s);
  else
    d->anth_nbr = 0;
  return (fd);
}
