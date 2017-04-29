/*
** my_str_to_wordtab.c for my_str_to_wordtab.c in /home/paul.prost/Tek1/Semestre2/Prog_Elem/CPE_2016_Lemin
** 
** Made by paul prost
** Login   <paul.prost@epitech.net>
** 
** Started on  Wed Apr 26 11:20:58 2017 paul prost
** Last update Sat Apr 29 19:05:18 2017 paul prost
*/

#include "my.h"

int	length2(char *str, int i, char c)
{
  int	len;

  len = 0;
  while (str[i] != c && str[i] != '\0')
    {
      i++;
      len++;
    }
  return (len);
}

char	**my_str_to_wordtab(char *str, int a, char c)
{
  int	len;
  char	**tab;
  int	i;
  int	n;
  int	j;

  j = (n = (i = 0));
  tab = malloc(sizeof(char *) * (a + 1));
  tab[a] = NULL;
  while (str[i] != '\0' && n < a)
    {
      len = length2(str, i, c);
      tab[n] = malloc(sizeof(char) * (len + 1));
      while (j < len)
	{
	  tab[n][j] = str[i];
	  j++;
	  i++;
	}
      tab[n][j] = '\0';
      n++;
      i++;
      j = 0;
    }
  return (tab);
}
