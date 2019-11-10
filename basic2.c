/*
** 
** Made by Moussa Hechaichi
** Login   <moussa.hechaichi@epitech.eu>
** 
** Started on  Tue Apr 25 16:45:12 2017 paul prost
** Last update Sat Apr 29 19:09:58 2017 paul prost
*/

#include "my.h"

int	check_num(char *str)
{
  int	i;

  i = 0;
  if (str[0] == '-')
    i++;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (1);
      i++;
    }
  return (0);
}

int	check_alpha(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] < '0' || (str[i] > '9' && str[i] < 'A') ||
	   (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z') && str[i] != '_')
	return (1);
      i++;
    }
  return (0);
}

int	my_putstr(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}

int	my_putstr_error(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar_error(str[i]);
      i = i + 1;
    }
  return (0);
}

int	my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}
