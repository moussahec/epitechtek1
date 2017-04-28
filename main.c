/*
** main.c for main.c in /home/paul.prost/Tek1/Semestre2/Prog_Elem/CPE_2016_Lemin
** 
** Made by paul prost
** Login   <paul.prost@epitech.net>
** 
** Started on  Tue Apr 25 16:39:29 2017 paul prost
** Last update Fri Apr 28 15:46:41 2017 paul prost
*/

#include "my.h"

int		read_file()
{
  char		*s;
  t_data        *d;
  t_list     *list;

  d = malloc(sizeof(t_data));
  d->tunnels = malloc(sizeof(char *) * 1);
  d->tunnels[0] = NULL;
  list = init_list();
  if ((s = anth_nbr(d)) == NULL)
    return (84);
  while (s != NULL)
    {
      if (s[0] == '#')
	handle_command(s, d, list);
      else if (check_tunnels(s) == 1)
	create_room(s, 0, d, list);
      else if ((check_tunnels(s) == 0) && (check_num(s) == 1))
	create_tunnels(s, list, d);
      s = get_next_line(0);
    }
  display(d);
  read_list(list, d);
  tunnels(d);
  return (0);
}

int	main()
{
  return (read_file());
}
