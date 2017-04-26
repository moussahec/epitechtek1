/*
** my_get_nbr.c for my_get_nbr.c in /home/paul.prost/Semestre1/Prog_Elem/CPE_2016_Pushswap
** 
** Made by paul prost
** Login   <paul.prost@epitech.net>
** 
** Started on  Wed Nov 23 14:48:09 2016 paul prost
** Last update Wed Apr 26 15:06:45 2017 paul prost
*/

#include "include/my.h"

int	my_get_nbr(char *nbr)
{
  int   n;
  int	i;
  int   res;

  n = 1;
  res = 0;
  i = my_strlen(nbr) - 1;
  while (i >= 0)
    {
      res = res + (n * (nbr[i] - 48));
      n = n * 10;
      i--;
    }
  if (nbr[0] == '-')
    res = res * -1;
  return (res);
}
