/*
** list.c for list.c in /home/paul.prost/Tek1/Semestre2/Prog_Elem/CPE_2016_Lemin
** 
** Made by paul prost
** Login   <paul.prost@epitech.net>
** 
** Started on  Tue Apr 25 11:42:42 2017 paul prost
** Last update Wed Apr 26 17:19:05 2017 paul prost
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

void	push_back(t_list *list, void *data)
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
  return (node);
}

void	read_list(t_list *list)
{
  t_node	*node;
  t_elem	*elem;

  elem = list->first;
  while (elem != NULL)
    {
      node = elem->data;
      printf("%s ", node->name);
      printf("%d ", node->posy);
      printf("%d\n", node->posx);
      elem = elem->next;
    }
}


/* void		main() */
/* { */
/*   t_list	*list; */
/*   t_node	*node; */
/*   t_elem	*elem; */

/*   list = init_list(); */
/*   node = create_nodes("Moussa", 0, 0); */
/*   push_back(list, node); */
/*   node = create_nodes("Moussa2", 0, 0); */
/*   push_back(list, node); */
/*   node = create_nodes("Moussa4", 0, 0); */
/*   push_back(list, node); */
/*   elem = list->first; */
/*   while (elem->next != NULL) */
/*     { */
/*       node = elem->data; */
/*       printf("%s\n", node->name); */
/*       elem = elem->next; */
/*     } */
/* } */
