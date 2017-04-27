/*
** get_next_line2.c for get_next_line.c in /home/paul.prost/Semestre1/CPE_2016_getnextline
** 
** Made by paul prost
** Login   <paul.prost@epitech.net>
** 
** Started on  Sun Jan 15 18:23:00 2017 paul prost
** Last update Wed Apr 26 18:49:05 2017 paul prost
*/

#include "my.h"

char	*end(t_gnl *d1, char *stock1)
{
  int	i;

  i = 0;
  d1->n_pos++;
  d1->stock_size = d1->size - d1->n_pos;
  if (d1->size > d1->n_pos)
    {
      d1->stock_size = d1->size - d1->n_pos;
      stock1 = malloc(sizeof(char *) * (d1->stock_size + 1));
      while (i < d1->stock_size)
	{
	  stock1[i] = d1->save[d1->n_pos];
	  i++;
	  d1->n_pos++;
	}
      stock1[i] = '\0';
    }
  else
    stock1 = NULL;
  return (stock1);
}

int	check_realloc(t_gnl *d1, char *str, int a)
{
  d1->n_pos = 0;
  while (str[d1->n_pos])
    {
      if (str[d1->n_pos] == '\n')
	return (2);
      d1->n_pos++;
    }
  if (a == 1)
    {
      d1->i = (d1->n = 0);
      d1->realloc = malloc(sizeof(char *) * d1->size);
      while (d1->n < d1->size)
	{
	  if (d1->n < (d1->size - d1->bytes))
	    d1->realloc[d1->n] = d1->save[d1->n];
	  else
	    {
	      d1->realloc[d1->n] = d1->read[d1->i];
	      d1->i++;
	    }
	  d1->n++;
	}
      d1->save = d1->realloc;
    }
  return (0);
}

void	create_line(t_gnl *d1, const int fd)
{
  d1->i = 0;
  if (check_realloc(d1, d1->save, 0) == 2 || d1->bytes < READ_SIZE)
    {
      if (d1->n_pos == 0)
	d1->line = malloc(sizeof(char *) * d1->n_pos);
      else
	{
	  d1->line = malloc(sizeof(char *) * d1->n_pos + 1);
	  while (d1->save[d1->i] != '\n' && d1->i < d1->size)
	    {
	      d1->line[d1->i] = d1->save[d1->i];
	      d1->i++;
	    }
	}
    }
  else if ((d1->bytes = read(fd, d1->read, READ_SIZE)) >= 0)
    {
      d1->size = d1->size + d1->bytes;
      check_realloc(d1, d1->save, 1);
      create_line(d1, fd);
    }
}

char		*initialisation(int fd, t_gnl *d1)
{
  static char	*stock = NULL;

  if (stock == NULL)
    {
      if (fd == -1 || (d1->bytes = read(fd, d1->read, READ_SIZE)) <= 0)
	return (NULL);
      if (d1->bytes == 2 && d1->read[0] == '\n')
	return ("\n\0");
      d1->save = malloc(sizeof(char *) * d1->bytes);
      d1->size = d1->bytes;
      check_realloc(d1, d1->save, 1);
      create_line(d1, fd);
    }
  else
    {
      d1->save = stock;
      while (stock[d1->size])
	d1->size++;
      stock = NULL;
      create_line(d1, fd);
    }
  d1->line[d1->i] = '\0';
  stock = end(d1, stock);
  return (NULL);
}

char		*get_next_line(const int fd)
{
  t_gnl		*d1;
  static int	a = 0;

  d1 = malloc(sizeof(t_gnl));
  a = a;
  d1->n_pos = 0;
  d1->size = 0;
  d1->bytes = 0;
  d1->stop = 0;
  d1->read = malloc(sizeof(char *) * (READ_SIZE + 1));
  d1->read[READ_SIZE] = '\0';
  if (initialisation(fd, d1) != NULL)
    {
      d1->line = malloc(sizeof(char *) * 2);
      d1->line[0] = '\n';
      d1->line[1] = '\0';
      return (d1->line);
    }
  return (d1->line);
}
