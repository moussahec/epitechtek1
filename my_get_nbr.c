/*
** 
** Made by Moussa Hechaichi
** Login   <moussa.hechaichi@epitech.eu>
** 
** Started on  Tue Apr 25 16:45:12 2017 paul prost
** Last update Sat Apr 29 19:09:58 2017 paul prost
*/

#include "include/my.h"

int	my_get_nbr(char *nbr)
{
  int   n;
  int   res;

  n = 0;
  res = 0;
  if (nbr[0] == '-')
    return (-1);
  while (nbr[n] != '\0')
    {
      res *= 10;
      res = res + (nbr[n] - 48);
      n++;
    }
  return (res);
}
