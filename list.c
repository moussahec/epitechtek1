/*
** list.c for list.c in /home/paul.prost/Tek1/Semestre2/Prog_Elem/CPE_2016_Lemin
** 
** Made by paul prost
** Login   <paul.prost@epitech.net>
** 
** Started on  Tue Apr 25 11:42:42 2017 paul prost
** Last update Sun Apr 30 22:46:48 2017 paul prost
*/

#include "include/my.h"

t_list		*init_list()
{
  t_list	*list;

  list = malloc(sizeof(t_list));
  list->size = 0;
  list->first = NULL;
  list->last = NULL;
  return (list);
}

void		push_back(t_list *list, void *data)
{
  t_elem	*elem;

  elem = malloc(sizeof(t_elem));
  elem->data = data;
  elem->next = NULL;
  elem->prev = list->last;
  if (list->last)
    {
      list->last->next = elem;
      list->last = elem;
    }
  else
    {
      list->first = elem;
      list->last = elem;
    }
  list->size++;
}

t_node		*create_nodes(char *name, int y, int x)
{
  t_node	*node;

  node = malloc(sizeof(t_node));
  node->name = name;
  node->posx = x;
  node->posy = y;
  node->full = 0;
  node->links = init_list();
  return (node);
}

void		read_list(t_list *list, t_data *d)
{
  t_node	*node;
  t_elem	*elem;

  elem = list->first;
  while (elem != NULL)
    {
      node = elem->data;
      if (my_strcmp(node->name, d->start) == 0 &&
	  my_strcmp(node->name, d->end) == 0)
	{
	  my_putstr(node->name);
	  my_putchar(' ');
	  my_put_nbr(node->posy);
	  my_putchar(' ');
	  my_put_nbr(node->posx);
	  my_putchar('\n');
	}
      elem = elem->next;
    }
}
