/*
** my_get_nbr.c for my_get_nbr.c in /home/paul.prost/Semestre1/Prog_Elem/CPE_2016_Pushswap
** 
** Made by paul prost
** Login   <paul.prost@epitech.net>
** 
** Started on  Wed Nov 23 14:48:09 2016 paul prost
** Last update Sat Apr 29 19:00:26 2017 paul prost
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
