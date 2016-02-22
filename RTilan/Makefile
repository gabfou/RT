# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/25 19:04:59 by gudepard          #+#    #+#              #
#    Updated: 2016/02/23 00:00:12 by ibuchwal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME				= rt

SRC_DIR 			= srcs
INCLUDE_DIR			= includes
OBJ_DIR				= objs

LIBFT				= ft
LIBFT_DIR			= libft
LIBFT_NAME			= $(LIBFT_DIR)/libft.a
LIBFT_INCLUDE_DIR	= $(LIBFT_DIR)/includes

X11FT = -lmlx -framework OpenGL -framework AppKit

COMPILER			=	gcc
CFLAGS				=	-O3 -Wall -Wextra -Werror -c \
						-I$(INCLUDE_DIR) -I$(LIBFT_INCLUDE_DIR)
LFLAGS				=	$(X11FT) -L$(LIBFT_DIR) -l$(LIBFT) -ltermcap -o

SRC					=	main.c			\
						errors.c		\
						read_token.c	\
						tokens.c		\
						parser.c


OBJ	=	$(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all: $(LIBFT_NAME) $(NAME)

$(LIBFT_NAME):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(COMPILER) $(LFLAGS) $@ $^

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(COMPILER) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJ)
	rm -df $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

