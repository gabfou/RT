/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:43:34 by gudepard          #+#    #+#             */
/*   Updated: 2014/02/26 14:29:18 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

/*
** Macros
*/
# define ABS(x) ((x) > 0 ? (x) : (-x))
# define UNUSED(x) ((void)(x))
# define WRITE(fd, what) (write(fd, what, sizeof(what) - 1))

/*
** Standard File descriptors
*/
# define STDIN	0
# define STDOUT	1
# define STDERR	2

/*
** Typedefs
*/
typedef unsigned char	t_uchar;
typedef int				t_int32;
typedef unsigned int	t_uint32;
typedef long			t_int64;
typedef unsigned long	t_uint64;

typedef void (*t_deleter)(void *, size_t);
typedef void (*t_map_deleter)(void *, void *);
typedef void (*t_functor)(void *, size_t, void *);
typedef void (*t_simple_functor)(void *, void *);
typedef int (*t_comparator)(void *, size_t, void *, size_t);
typedef t_uint64 (*t_hash_func)(const void *, size_t);
typedef t_uint64 (*t_simple_hash_func)(const void *);

/*
** Standard library
*/
void		*ft_memset(void *b, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *s1, const void *s2, size_t n);
void		*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void		*ft_memmove(void *s1, const void *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *str);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strncpy(char *dst, const char *src, size_t n);
char		*ft_strcat(char *dst, const char *src);
char		*ft_strncat(char *dst, const char *src, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *s1, const char *s2);
char		*ft_strnstr(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

/*
** Tools
*/
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(size_t, char *));
char		*ft_strmap(const char *s, char (*f)(char));
char		*ft_strmapi(const char *s, char (*f)(size_t, char));
int			ft_strequ(const char *s1, const char *s2);
int			ft_strnequ(const char *s1, const char *s2, size_t n);
char		*ft_strsub(const char *s, size_t start, size_t len);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strtrim(const char *s);
char		**ft_strsplit(const char *s, char c);
char		*ft_itoa(int n);
void		ft_putchar(char c);
void		ft_putstr(const char *str);
void		ft_putendl(const char *s);
void		ft_putnbr(int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(const char *str, int fd);
void		ft_putendl_fd(const char *str, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_max(int a, int b);
size_t		ft_umax(size_t a, size_t b);
int			ft_min(int a, int b);
size_t		ft_umin(size_t a, size_t b);
# define BUFF_SIZE 4096
int			get_next_line(const int fd, char **line);

/*
** Lists
*/
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list		*ft_lstnew(const void *content, size_t content_size);
void		ft_lstdelone(t_list **alst, t_deleter del);
void		ft_lstdel(t_list **alst, t_deleter del);
void		ft_lstadd(t_list **alst, t_list *new_element);
t_list		*ft_lstremove(t_list **alst, void *e, size_t s, t_comparator cmp);
void		ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list		*ft_lstmap(t_list *lst, t_list * (*f)(t_list *elem));
void		ft_lstappend(t_list **alst, t_list *new_element);
void		ft_lstforeach(t_list *lst, t_functor functor, void *data);
size_t		ft_lstsize(t_list *lst);

typedef struct s_dlist	t_dlist;
struct		s_dlist
{
	void	*content;
	size_t	content_size;
	t_dlist	*previous;
	t_dlist	*next;
};

t_dlist		*ft_dlist_new(void *content, size_t content_size);
void		ft_dlist_append(t_dlist **head, t_dlist *new_elem);
void		ft_dlist_remove(t_dlist **head, t_dlist *elem, t_deleter del);
void		ft_dlist_foreach(t_dlist *list, t_functor functor, void *data);
void		ft_dlist_delete(t_dlist **head, t_deleter del);
size_t		ft_dlist_size(t_dlist *list);

/*
** Trees
*/
typedef struct s_btree	t_btree;
struct		s_btree
{
	t_btree	*left;
	t_btree	*right;
	void	*content;
	size_t	content_size;
};

t_btree		*ft_btree_new(void *content, size_t content_size);
void		ft_btree_insert(t_btree **root, t_btree *node, t_comparator cmp);
t_btree		*ft_btree_find(t_btree *node, void *n, size_t s, t_comparator cmp);
void		ft_btree_pre_foreach(t_btree *root, t_functor functor, void *d);
void		ft_btree_inf_foreach(t_btree *root, t_functor functor, void *d);
void		ft_btree_post_foreach(t_btree *root, t_functor functor, void *d);
t_btree		*ft_btree_remove(t_btree **r, void *n, size_t s, t_comparator cmp);
void		ft_btree_delete(t_btree **root, t_deleter del);

# define MAP_TREE_SIZE 4096
typedef t_btree*	t_map[MAP_TREE_SIZE];

typedef struct	s_map_entry
{
	void		*key;
	void		*value;
	t_uint64	_hash;
}				t_map_entry;

typedef struct	s_map_entry2
{
	const void	*key;
	size_t		key_size;
	void		*value;
	size_t		value_size;
	t_uint64	_hash;
}				t_map_entry2;

typedef struct	s_data
{
	void		*content;
	size_t		content_size;
}				t_data;

void		ft_map_insert(t_map map, t_map_entry entry, t_simple_hash_func h_f);
void		*ft_map_get(t_map map, void *key, t_simple_hash_func h_f);
t_map_entry	*ft_map_get_p(t_map map, void *key, t_simple_hash_func h_f);
void		ft_map_remove(t_map map, void *key, t_simple_hash_func f,
							t_map_deleter del);
void		ft_map_delete(t_map map, t_map_deleter del);
void		ft_map_foreach(t_map map, t_simple_functor functor, void *data);

t_uint64	ft_djb2(const char *str);

/*
** Colors
*/
# define FG_COLOR_TYPE "38;5"
# define BG_COLOR_TYPE "48;5"

void		ft_setfgcolor(t_uchar color);
void		ft_setbgcolor(t_uchar color);
void		ft_resetcolor(void);

#endif /* LIBFT_H */
