

SRC	=	basic2.c		\
		my_str_to_wordtab.c	\
		str_to_wordtab.c	\
		realloc_tab.c		\
		list.c			\
		basic.c			\
		parse.c			\
		main.c			\
		get_next_line.c		\
		my_get_nbr.c		\
		error.c			\
		display.c		\


OBJ	=	$(SRC:.c=.o)

NAME	=	lem_in

CFLAGS	=	-Iinclude -W -Wall

all:		$(NAME)

$(NAME):        $(OBJ)
		gcc $(OBJ) $(CFLAGS) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		clean all

.PHONY:		all clean fclean re
