# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/23 23:09:04 by jromagna          #+#    #+#              #
#    Updated: 2016/03/28 23:40:51 by ibuchwal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

SRC =  rtv1.c \
	   light.c \
	   new_t.c \
	   new_t2.c \
	   new_t3.c \
	   set.c \
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
	   read_token.c	\
	   errors.c	\
	   tokens.c \
	   parser.c \
	   transparencator.c \
	   reader.c \
	   init.c \
	   misc.c \
	   controlpanelator.c \
	   musicator.c \
	   initauxi.c \
	   initauxi2.c \
	   opticator.c \
	   initform.c \
	   initauxi3.c \
	   initformauxi.c \
	   info.c \
	   modifitem.c	\
	   carresisator.c \
	   impactcarre.c \
	   calc.c \
	   calc2.c \
	   fatoipos.c \
	   creatorauxi.c \
	   hook.c \
	   comand.c \
	   modifitem2.c \
	   triangle.c \
	   objreader.c \
	   obj.c \
	   initauxi4.c \
	   carreform.c \
	   lightauxi.c \
	   helios.c \
	   helios_2.c \
	   opticatorancien.c \
	  
OBJ = $(SRC:.c=.o)
CC = clang
CFLAGS = -Wall -Wextra -Werror -g3 # -fsanitize=address
LFLAGS = -L libft -lpthread -lft -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@echo "libft start"
	@make -C libft
	@echo "libft ok"
	@echo "comp start"
	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) -o $(NAME)
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

