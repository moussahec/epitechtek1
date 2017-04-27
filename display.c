/*
** display.c for display.c in /home/paul.prost/Tek1/Semestre2/Prog_Elem/CPE_2016_Lemin
** 
** Made by paul prost
** Login   <paul.prost@epitech.net>
** 
** Started on  Thu Apr 27 17:02:45 2017 paul prost
** Last update Thu Apr 27 17:27:32 2017 paul prost
*/

#include "my.h"

void	display_inf(t_data *d)
{
  my_putstr("#number_of_ants\n");
  my_put_nbr(d->anth_nbr);
  my_putstr("\n#rooms\n");
  my_putstr("##start\n");
  my_putstr(d->start);
  my_putchar(' ');
  my_put_nbr(d->start_posy);
  my_putchar(' ');
  my_put_nbr(d->start_posx);
  my_putchar('\n');
  my_putstr("##end\n");
  my_putstr(d->end);
  my_putchar(' ');
  my_put_nbr(d->end_posy);
  my_putchar(' ');
  my_put_nbr(d->end_posx);
  my_putchar('\n');
}

