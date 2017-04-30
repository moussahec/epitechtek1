/*
** str_to_wordtab.c for str_to_wordtab.c in /home/paul.prost/Tek1/Semestre2/Prog_Elem/CPE_2016_Lemin
** 
** Made by paul prost
** Login   <paul.prost@epitech.net>
** 
** Started on  Sat Apr 29 18:05:55 2017 paul prost
** Last update Sun Apr 30 22:40:48 2017 paul prost
*/

#include "my.h"

int	length(char *str1)
{
  int	i;
  int	n;
  int	x;

  i = 0;
  n = 0;
  x = 0;
  while (str1[i] != 0)
    {
      if (str1[i] == ' ' || str1[i] == '\t')
	{
	  while (str1[i] == ' ' || str1[i] == '\t')
	    i++;
	  if (n > x)
	    x = n;
	  n = 1;
	}
      else
	n++;
      i++;
    }
  if (n > x)
    x = n;
  return (x);
}

int	words(char *str1)
{
  int	i;
  int	x;

  x = 1;
  i = 0;
  while (str1[i] == ' ' || str1[i] == '\t' || str1[i] == '\n')
    i++;
  while (str1[i] != 0)
    {
      if (str1[i] == ' ' || str1[i] == '\t')
	{
	  while (str1[i] == ' ' || str1[i] == '\t')
	    i = i + 1;
	  if (str1[i] != 0)
	    x = x + 1;
	}
      i = i + 1;
    }
  return (x);
}

void	fill_tab(char **str, char *str1, t_data *d)
{
  int	i;

  i = (d->x = (d->y = 0));
  while (str1[i] == ' ' || str1[i] == '\t')
    i++;
  while (str1[i] != 0)
    {
      if (str1[i] == ' ' || str1[i] == '\t')
	{
	  str[d->y][d->x] = '\0';
	  while (str1[i] == ' ' || str1[i] == '\t')
	    i++;
	  d->y++;
	  if (str1[i] != 0)
	    d->x = 0;
	  else
	    d->y--;
	}
      else
	{
	  str[d->y][d->x] = str1[i];
	  d->x++;
	  i++;
	}
    }
}

char	**str_to_wordtab(char *str1, t_data *d)
{
  char	**str;
  int	word;
  int	len;
  int	i;

  i = 0;
  if (str1[0] == 0)
    return (NULL);
  word = words(str1);
  len = length(str1);
  str = malloc(sizeof(char *) * (word + 1));
  while (i < word)
    {
      str[i] = malloc(sizeof(char) * len + 1);
      i++;
    }
  fill_tab(str, str1, d);
  str[d->y + 1] = NULL;
  str[d->y][d->x] = '\0';
  return (str);
}
