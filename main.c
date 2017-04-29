/*
** main.c for main.c in /home/paul.prost/Tek1/Semestre2/Prog_Elem/CPE_2016_Lemin
** 
** Made by paul prost
** Login   <paul.prost@epitech.net>
** 
** Started on  Tue Apr 25 16:39:29 2017 paul prost
** Last update Sat Apr 29 20:29:53 2017 paul prost
*/

#include "my.h"

int		read_file(t_data *d, t_list *list)
{
  char		*s;

  if ((s = anth_nbr(d)) == NULL)
    return (84);
  while (s != NULL)
    {
      if (s[0] == '#')
	{
	  if (handle_command(s, d, list) == 84)
	    return (84);
	}
      else if ((check_tunnels(s) == 1) && (check_words(s, d) == 3))
	create_room(s, 0, d, list);
      else if ((check_tunnels(s) == 0) && (check_num(s) == 1))
	if (create_tunnels(s, list, d) == 84)
	  return (0);
      s = get_next_line(0);
    }
  return (0);
}

int	launch(t_data *d, t_list *list)
{
  display(d);
  read_list(list, d);
  tunnels(d);
  if (d->start == NULL || d->end == NULL)
    return (84);
  if (d->tunnels[0] == NULL)
    return (84);
  return (0);
}

int	init()
{
  t_data        *d;
  t_list     *list;

  d = malloc(sizeof(t_data));
  d->tunnels = malloc(sizeof(char *) * 1);
  d->tunnels[0] = NULL;
  d->start = NULL;
  d->end = NULL;
  list = init_list();
  if (read_file(d, list) == 84)
    return (84);
  return (launch(d, list));
}

int	main()
{
  return (init());
}
