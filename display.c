/*
** display.c for display.c in /home/paul.prost/Tek1/Semestre2/Prog_Elem/CPE_2016_Lemin
** 
** Made by paul prost
** Login   <paul.prost@epitech.net>
** 
** Started on  Thu Apr 27 17:02:45 2017 paul prost
** Last update Sun Apr 30 22:45:53 2017 paul prost
*/

#include "my.h"

void	tunnels(t_data *d)
{
  int	i;

  i = 0;
  my_putstr("#tunnels\n");
  while (d->tunnels[i])
    {
      my_putstr(d->tunnels[i]);
      my_putchar('\n');
      i++;
    }
}

void	display(t_data *d)
{
  my_putstr("#number_of_ants\n");
  my_put_nbr(d->anth_nbr);
  my_putstr("\n#rooms\n");
  start_room(d);
  end_room(d);
}

void	start_room(t_data *d)
{
  if (d->start != NULL)
    {
      my_putstr("##start\n");
      my_putstr(d->start);
      my_putchar(' ');
      my_put_nbr(d->start_posy);
      my_putchar(' ');
      my_put_nbr(d->start_posx);
      my_putchar('\n');
    }
}

void	end_room(t_data *d)
{
  if (d->end != NULL)
    {
      my_putstr("##end\n");
      my_putstr(d->end);
      my_putchar(' ');
      my_put_nbr(d->end_posy);
      my_putchar(' ');
      my_put_nbr(d->end_posx);
      my_putchar('\n');
    }
}
