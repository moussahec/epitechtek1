/*
** parse.c for parse.c in /home/paul.prost/Tek1/Semestre2/Prog_Elem/CPE_2016_Lemin
** 
** Made by paul prost
** Login   <paul.prost@epitech.net>
** 
** Started on  Wed Apr 26 11:05:20 2017 paul prost
** Last update Sat Apr 29 20:33:05 2017 paul prost
*/

#include "my.h"

int	handle_command(char *s, t_data *d, t_list *list)
{
  if ((my_strcmp(s, "##start") == 1) && (d->start == NULL))
    {
      while (s[0] == '#')
	s = get_next_line(0);
      if (check_tunnels(s) == 1)
	create_room(s, 1, d, list);
      else
	d->start = NULL;
    }
  else if ((my_strcmp(s, "##end") == 1) && (d->end == NULL))
    {
      while (s[0] == '#')
	s = get_next_line(0);
      if (check_tunnels(s) == 1)
	create_room(s, 2, d, list);
      else
	d->end = NULL;
    }
  else if ((my_strcmp(s, "##end") == 1) || (my_strcmp(s, "##start") == 1))
    return (84);
  return (0);
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
  if (elem == NULL)
    return (NULL);
  node = elem->data;
  while (my_strcmp(node->name, name) != 1 && (elem->next != NULL))
    {
      elem = elem->next;
      node = elem->data;
    }
  if (my_strcmp(node->name, name) == 1)
    return (node);
  else
    return (NULL);
}

int		create_tunnels(char *s, t_list *list, t_data *d)
{
  char		**tab;
  char		**tab1;
  t_node	*node1;
  t_node	*node2;

  if (tunnels_error(s) == 84)
    return (84);
  tab1 = str_to_wordtab(s, d);
  tab = my_str_to_wordtab(tab1[0], 2, '-');
  if ((node1 = find_room(list, tab[0])) == NULL)
    return (84);
  if ((node2 = find_room(list, tab[1])) == NULL)
    return (84);
  if (check_error(node1->links, node2->name) == 84)
    return (84);
  realloc_tab(s, d);
  push_back(node1->links, node2);
  push_back(node2->links, node1);
  return (0);
}

char	*anth_nbr(t_data *d)
{
  char	*s;
  char	**tab;

  if ((s = get_next_line(0)) == NULL)
    return (NULL);
  while (s != NULL && (s[0] == '#' && (my_strcmp(s, "##start") == 0)))
    s = get_next_line(0);
  if (s == NULL)
    return (NULL);
  tab = str_to_wordtab(s, d);
  if (check_num(tab[0]) == 0)
    d->anth_nbr = my_get_nbr(tab[0]);
  else
    return (NULL);
  if (d->anth_nbr < 0)
    return (NULL);
  return (s);
}
