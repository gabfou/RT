/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 21:21:46 by ibuchwal          #+#    #+#             */
/*   Updated: 2016/02/25 22:57:44 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PARSER_H
# define	PARSER_H

# include "rtv1.h"

/*
** Standard File descriptors
*/
# define STDIN	0
# define STDOUT	1
# define STDERR	2

/*
** Macros
*/
# define WRITE(fd, what) (write(fd, what, sizeof(what) - 1))



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
# define UNIVERSE				"I just saved the universe"
# define ERROR				"ERROR"




/*
** Lexer
*/

typedef struct s_symbol		t_symbol;
typedef struct s_obj		t_obj;
typedef struct s_obj		t_obj;
typedef struct s_token		t_token;
typedef int (*t_stream_reader)(char **, t_token *);

typedef enum	e_token_type
{
	OPENING_BRACKET,
	CLOSING_BRACKET,
	WORD,
	COLON,
	COMMA
} t_token_type;

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
// int			read_token(char **stream, t_token *token, int line_number);
t_list		*tokenize(char *string, int line_number);
int			is_whitespace(char c);
void		ignore_whitespaces(char **stream);
void		free_token(void *p_token, size_t size);


int			terminal(t_list **tokens, t_token_type type);
t_token		*get_token(t_list **tokens);
// int			parse_exp(t_list **tokens, t_env *par);

void		next_elem(t_list **elems);
void		print_tokens(t_list *tokens);

int			parsetout(int fd);


void	fatal_error(const char *name, const char *error, const char *info);



#endif
