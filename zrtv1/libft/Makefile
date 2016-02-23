# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jromagna <jromagna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 15:50:50 by jromagna          #+#    #+#              #
#    Updated: 2014/12/23 18:08:43 by jromagna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isdigit.c \
	  ft_strchr.c \
	  ft_strncmp.c \
	  ft_toupper.c \
	  ft_isprint.c \
	  ft_strcmp.c \
	  ft_strncpy.c \
	  ft_putchar.c \
	  ft_strcpy.c \
	  ft_strnstr.c \
	  ft_isalnum.c \
	  ft_putnbr.c \
	  ft_strdup.c \
	  ft_strrchr.c \
	  ft_isalpha.c \
  	  ft_putstr.c \
	  ft_strlen.c \
	  ft_strstr.c \
	  ft_isascii.c \
	  ft_strcat.c\
  	  ft_strncat.c \
	  ft_tolower.c \
	  ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_atoi.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strclr.c \
	  ft_strdel.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strtrim.c \
	  ft_strjoin.c \
	  ft_strsub.c \
	  ft_strsplit.c \
	  ft_itoa.c \
	  ft_strsplit.c \
	  ft_strlcat.c \
	  ft_putendl.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putnbr_fd.c \
	  ft_putendl_fd.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_tabswap.c \
	  get_next_line.c \
	  ft_error.c

all : $(NAME)
OBJ	= $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
