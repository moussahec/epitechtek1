/*
** my_get_nbr.c for my_get_nbr.c in /home/paul.prost/Semestre1/Prog_Elem/CPE_2016_Pushswap
** 
** Made by paul prost
** Login   <paul.prost@epitech.net>
** 
** Started on  Wed Nov 23 14:48:09 2016 paul prost
** Last update Sat Apr 29 17:25:01 2017 paul prost
*/

#include "include/my.h"

int	my_get_nbr(char *nbr)
{
  int   n;
  int   res;

  n = 0;
  res = 0;
  if (nbr[0] == '-')
    n++;
  while (nbr[n])
    {
      res *= 10;
      res = res + (nbr[n] - 48);
      n++;
    }
  if (nbr[0] == '-')
    res = res * -1;
  return (res);
}
