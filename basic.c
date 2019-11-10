/*
** 
** Made by Moussa Hechaichi
** Login   <moussa.hechaichi@epitech.eu>
** 
** Started on  Tue Apr 25 16:45:12 2017 paul prost
** Last update Sat Apr 29 19:09:58 2017 paul prost
*/

#include "my.h"

int	check_tunnels(char *s)
{
  int	i;

  i = 0;
  while (s[i])
    if (s[i++] == ' ')
      return (1);
  return (0);
}

int	my_strcmp(char *str, char *abc)
{
  int   i;

  i = 0;
  if ((str == NULL && abc != NULL) || (str != NULL && abc == NULL))
    return (0);
  if (my_strlen(str) != my_strlen(abc))
    return (0);
  while (i < my_strlen(str))
    {
      if (str[i] != abc[i])
	return (0);
      i = i + 1;
    }
  return (1);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putchar_error(char c)
{
  write(2, &c, 1);
}

int	my_put_nbr(int nbr)
{
  int   nombre;

  if (nbr < 0)
    {
      nbr = nbr * -1;
      my_putchar('-');
    }
  if (nbr / 10 < 0)
    return (0);
  if (nbr / 10 > 0)
    {
      my_put_nbr(nbr / 10);
      nombre = nbr;
      my_put_nbr(nombre % 10);
      return (nbr);
    }
  my_putchar(nbr + 48);
  return (0);
}
