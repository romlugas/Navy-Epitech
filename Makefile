##
## Makefile for navy in /home/boissi_p/rendu/PSU_2016_navy
##
## Made by Pierre-Malick Boissiere
## Login   <boissi_p@epitech.net>
##
## Started on  Mon Jan 30 10:30:53 2017 Pierre-Malick Boissiere
## Last update Sun Feb 19 23:28:18 2017 Pierre-Malick Boissiere
##

CC	= gcc

SRCS	= main.c		\
	  navy.c		\
	  wordtab.c		\
	  get_next_line.c	\
	  map.c			\
	  toolbox.c		\
	  sighandlers.c		\
	  communication.c	\
	  bytes.c		\
	  game.c		\
	  attacks.c		\
	  error.c		\
	  errfonct.c		\
	  errfonctions.c	\
	  my_strcapitalize.c	\

CFLAGS  += -I./include
CFLAGS  += -Wall -W -Wextra # -Werror
CFLAGS  += -pedantic -ansi

HEAD	= my.h		\
	  proto.h	\
	  lib.h		\
	  structure.h	\
	  macrow.h	\

OBJS	= $(addprefix src/, $(SRCS:.c=.o))

NAME	= navy

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

all:	$(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
