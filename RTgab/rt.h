/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 14:03:53 by ibuchwal          #+#    #+#             */
/*   Updated: 2016/01/06 20:51:47 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		RT_H
# define	RT_H

# include <mlx.h>
# include "libft.h"
# include <fcntl.h>
# include <time.h>
# include <math.h>
# include <stdio.h>

# define RETURN_ERROR			-1
# define RETURN_SUCCESS			0
# define WORD_CHARS				"_-"
// # define NOT_CHARACTER			"!@#$%^&*()+=~`|\\[]';\"?/><"

# define RAYTRACER				"rt"
# define ERR_SEPARATOR			": "
# define ERR_TOO_MANY_ARGS		"Too many arguments"
# define ERR_TOO_FEW_ARGS		"Too few arguments"
# define ERR_NO_DIR				"No such file or directory"
# define ERR_PERMISSION_DENIED	"Permission denied"
# define ERR_INACCESSIBLE		"File is inaccessible"

typedef struct s_shape		t_shape;
typedef unsigned int		t_uint32;

struct 				s_shape
{
	double			pos_x;
	double			pos_y;
	double			pos_z;
	double			radius;
	t_uint32		color;
};


/*
** Lexer
*/

typedef struct s_symbol		t_symbol;
typedef struct s_obj		t_obj;
typedef struct s_obj		t_obj;
typedef struct s_token		t_token;
typedef int (*t_stream_reader)(char **, t_token *);
typedef enum e_token_type	t_token_type;

enum	e_token_type
{
	OPENING_BRACKET,
	CLOSING_BRACKET,
	WORD,
	COLON,
	COMMA
};

struct				s_token
{
	t_token_type	type;
	char			*lexeme;
	int				line;
};

struct 				s_symbol
{
	t_token_type	type;
	char			c;
};

int			read_opening_bracket(char **stream, t_token *token);
int			read_closing_bracket(char **stream, t_token *token);
int			read_colon(char **stream, t_token *token);
int			read_comma(char **stream, t_token *token);
int			read_token(char **stream, t_token *token, int line_number);
t_list		*tokenize(char *string, int line_number);
int			is_whitespace(char c);
void		ignore_whitespaces(char **stream);
void		free_token(void *p_token, size_t size);


int			terminal(t_list **tokens, t_token_type type);
t_token		*get_token(t_list **tokens);
int			parse_exp(t_list **tokens);


void	fatal_error(const char *name, const char *error, const char *info);



#endif		/* !RT_H */
