##
## Makefile for Makefile in /home/paul.prost/Tek1/Semestre2/Prog_Elem/CPE_2016_Lemin
## 
## Made by paul prost
## Login   <paul.prost@epitech.net>
## 
## Started on  Tue Apr 25 16:35:02 2017 paul prost
## Last update Fri Apr 28 11:10:47 2017 paul prost
##

SRC	=	basic2.c		\
		my_str_to_wordtab.c	\
		realloc_tab.c		\
		list.c			\
		basic.c			\
		parse.c			\
		main.c			\
		get_next_line.c		\
		my_get_nbr.c		\
		display.c		\


OBJ	=	$(SRC:.c=.o)

NAME	=	lem_in

CFLAGS	=	-Iinclude -g3 -W -Wall

all:		$(NAME)

$(NAME):        $(OBJ)
		gcc $(OBJ) $(CFLAGS) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		clean all

.PHONY:		all clean fclean re
