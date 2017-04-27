/*
** parse.c for parse.c in /home/paul.prost/Tek1/Semestre2/Prog_Elem/CPE_2016_Lemin
** 
** Made by paul prost
** Login   <paul.prost@epitech.net>
** 
** Started on  Wed Apr 26 11:05:20 2017 paul prost
** Last update Thu Apr 27 22:01:16 2017 paul prost
*/

#include "my.h"

int	handle_command(int fd, char *s, t_data *d, t_list *list)
{
  if (my_strcmp(s, "##start") == 1)
    {
      while (s[0] == '#')
	s = get_next_line(fd);
      if (check_tunnels(s) == 1)
	create_room(s, 1, d, list);
      else
	d->start = NULL;
    }
  else if (my_strcmp(s, "##end") == 1)
    {
      while (s[0] == '#')
	s = get_next_line(fd);
      if (check_tunnels(s) == 1)
	create_room(s, 2, d, list);
      else
	d->end = NULL;
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

t_node	*find_room(t_list *list, char *name)
{
  t_node        *node;
  t_elem        *elem;

  elem = list->first;
  node = elem->data;
  while (my_strcmp(node->name, name) != 1 && (elem != NULL))
    {
      elem = elem->next;
      node = elem->data;
    }
  return (node);
}

void		create_tunnels(char *s, t_list *list, t_data *d)
{
  char		**tab;
  t_node	*node1;
  t_node	*node2;

  realloc_tab(s, d);
  tab = my_str_to_wordtab(s, 2, '-');
  node1 = find_room(list, tab[0]);
  node2 = find_room(list, tab[1]);
  push_back(node1->links, node2);
  push_back(node2->links, node1);
}

char	*anth_nbr(int fd, t_data *d)
{
  char	*s;

  if ((s = get_next_line(fd)) == NULL)
    return (NULL);
  while (s[0] == '#' && (my_strcmp(s, "##start") == 0))
    s = get_next_line(fd);
  if (check_num(s) == 0)
    d->anth_nbr = my_get_nbr(s);
  else
    d->anth_nbr = 0;
  return (s);
}
