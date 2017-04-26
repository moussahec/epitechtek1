/*
** main.c for main.c in /home/paul.prost/Tek1/Semestre2/Prog_Elem/CPE_2016_Lemin
** 
** Made by paul prost
** Login   <paul.prost@epitech.net>
** 
** Started on  Tue Apr 25 16:39:29 2017 paul prost
** Last update Wed Apr 26 16:48:51 2017 paul prost
*/

#include "my.h"

int		read_file(int fd)
{
  char		*s;
  t_data        *d;
  t_list     *list;

  d = malloc(sizeof(t_data));
  list = init_list();
  fd = anth_nbr(fd, d);
  while ((s = get_next_line(fd)))
    {
      if (s[0] == '#')
	fd = handle_command(fd, s, d, list);
      else if (check_tunnels(s) == 1)
	create_room(s, 0, d, list);
      else if (check_tunnels(s) == 0)
	create_tunnels(s);
    }
  read_list(list);
  return (0);
}

int	open_file(char *name)
{
  int	fd;

  if ((fd = open(name, O_RDONLY)) == -1)
    return (84);
  read_file(fd);
  return (0);
}

int		main(int ac, char **av)
{
  if (ac == 2)
    return (open_file(av[1]));
  else
    return (84);
}
