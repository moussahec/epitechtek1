/*
** my.h for my.h in /home/paul.prost/Tek1/Semestre2/Prog_Elem/CPE_2016_Lemin
** 
** Made by paul prost
** Login   <paul.prost@epitech.net>
**
** Started on  Tue Apr 25 11:42:26 2017 paul prost
** Last update Thu Apr 27 22:09:24 2017 paul prost
*/

#ifndef MY_H_
# define MY_H_

#ifndef READ_SIZE
# define READ_SIZE (1)
#endif

typedef struct	s_elem
{
  void		*data;
  struct s_elem	*next;
  struct s_elem	*prev;
}		t_elem;

typedef struct  s_gnl
{
  char  *save;
  char  *read;
  char  *realloc;
  char  *line;
  int   stop;
  int   size;
  int   n_pos;
  int   i;
  int   n;
  int   bytes;
  int   stock_size;
}               t_gnl;

typedef struct	s_list
{
  int		size;
  t_elem	*first;
  t_elem	*last;
}		t_list;

typedef struct          s_node
{
  char                  *name;
  int			posy;
  int			posx;
  int			full;
  t_list		*links;
}                       t_node;

typedef struct  s_data
{
  char	**tunnels;
  char	*start;
  char	*end;
  int	anth_nbr;
  int	start_posx;
  int	start_posy;
  int	end_posx;
  int	end_posy;
}		t_data;

#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	my_putchar_error(char);
void	tunnels(t_data *);
void	realloc_tab(char *, t_data *);
t_node	*find_room(t_list *, char *);
void	display(t_data *);
void	start_room(t_data *);
void	end_room(t_data *);
int	my_get_nbr(char *);
int	my_put_nbr(int);
int	check_num(char *);
void	read_list(t_list *, t_data *);
int	handle_command(int, char *, t_data *, t_list *);
t_node	*create_nodes(char *, int, int);
char	**my_str_to_wordtab(char *, int, char);
t_list	*init_list();
char	*anth_nbr(int, t_data *);
void	create_tunnels(char *, t_list *, t_data *);
int	check_tunnels(char *);
void	my_exit();
void	push_back(t_list *, void *);
int	my_strlen(char *);
int	check_alpha(char *);
int	my_strcmp(char *, char *);
void	create_room(char *, int, t_data *, t_list *);
int	my_putstr_error(char *);
char	*get_next_line(int);
void	my_putchar(char);
int	my_putstr(char *);
int	my_put_nbr(int);
void	show_wordtab(t_data *, char **);
char	*my_strcat(char *, char *, t_data *);

#endif /* MY_H_ */
