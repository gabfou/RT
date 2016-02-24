# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 15:50:50 by gfournie          #+#    #+#              #
#    Updated: 2014/12/23 18:08:43 by gfournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Rtv1

SRC = rayonator.c \
	  coliator.c \
	  get_next_line.c \
	  mainator.c \
	  misc.c \
	  misc2.c \
	  recuperator.c \
	  recuperatoraux.c \
	  translator.c \
	  proprator.c \
	  proprator2.c \
	  propretor3.c \
	  pars2.c \
	  opticator.c \
	  hud.c


all : $(NAME)
OBJ	= $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror -O3

$(NAME): $(OBJ)
	gcc $(FLAG) -c $(SRC)
	gcc -o $(NAME) $(FLAG) $(OBJ) ./libft/libft.a -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
