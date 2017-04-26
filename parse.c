/*
** parse.c for parse.c in /home/paul.prost/Tek1/Semestre2/Prog_Elem/CPE_2016_Lemin
** 
** Made by paul prost
** Login   <paul.prost@epitech.net>
** 
** Started on  Wed Apr 26 11:05:20 2017 paul prost
** Last update Wed Apr 26 16:43:27 2017 paul prost
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
  tab = my_str_to_wordtab(s);
  if (a == 1)
    d->start = tab[0];
  else if (a == 2)
    d->end = tab[0];
  node = create_nodes(tab[0], my_get_nbr(tab[1]), my_get_nbr(tab[2]));
  push_back(list, node);
}

void	create_tunnels(char *s)
{
  s = s;
}

int	anth_nbr(int fd, t_data *d)
{
  char	*s;

  s = get_next_line(fd);
  while (s[0] == '#')
    s = get_next_line(fd);
  d->anth_nbr = my_get_nbr(s);
  return (fd);
}
