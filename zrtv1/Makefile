# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jromagna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/23 23:09:04 by jromagna          #+#    #+#              #
#    Updated: 2015/10/23 23:09:06 by jromagna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

SRC =  rtv1.c \
	   light.c \
	   new_t.c \
	   set.c \
	   pars.c \
	   pars2.c \
	   plane.c \
	   cone.c \
	   pyl.c \
	   sphere.c \
	   creator.c \
	   auxi.c \
	   hud.c \
	   thread.c \
	   enregistrator.c \
	   antialiasing.c \
	   


OBJ = $(SRC:.c=.o)
CC = clang
CFLAGS = -Wall -Wextra -Werror -O3 -g

all: $(NAME)

$(NAME): $(OBJ)
	@echo "libft start"
	@make -C libft
	@echo "libft ok"
	@echo "comp start"
	@$(CC) $(CFLAGS) -L libft -lpthread -lft -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)
	@echo "ALL DONE"

norm:
	norminette **[ch]

clean:
	@echo "cleaning .o"
	@/bin/rm -f $(OBJ)
	@make -C libft clean
	@echo "cleaning .o done"
				 
fclean: clean
	@echo "cleaning NAME"
	@/bin/rm -f $(NAME)
	@make -C libft fclean
	@echo "cleaning NAME done"

re: fclean all

