##
## Makefile for Makefile in /home/clement/Documents/piscine/lib/lenour_c/libmy_01
## 
## Made by LENOURS ClÃ©ment
## Login   <lenour_c@etna-alternance.net>
## 
## Started on  Sat Oct 22 18:18:08 2016 LENOURS ClÃ©ment
## Last update Sat Nov 12 12:17:00 2016 LENOURS Clément
##
CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=my_ftl
SRC=my_ftl.c air_shed.c readline.c system_repair.c container.c my_string.c system_control.c action.c game.c my_put_nbr.c my_rand.c ennemy.c attack.c
OBJS=$(SRC:.c=.o)
RM=rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
