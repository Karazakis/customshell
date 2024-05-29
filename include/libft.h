/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:43:28 by dimolin2          #+#    #+#             */
/*   Updated: 2023/08/15 16:40:47 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "get_next_line.h"
# include "libftprintf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct i_list
{
	int				content;
	struct i_list	*next;
}					t_intl;

int					ft_atoi(const char *nptr);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_strlen(const char *s);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strdup(const char *s);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
int					ft_putstr_fd(char *s, int fd);
int					ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/* custom functions */
int					ft_iswhite(char c);
int					ft_countmatrix_char(char **matrix, char c);
void				ft_free_matrix(char ***matrix);
char				*ft_free_matrix_nomat(char **matrix, int i);
char				*ft_free_matrix_xy(char ***matrix, int x, int y);
void				ft_sleep_kinda(size_t k);
void				ft_putstr(char *s);
void				intlist_delone(t_intl **st_n);
void				intlist_clear(t_intl **st_n);
int					ft_atoi_hex(char *str);
int					ft_ishex(char *str);
int					ft_count_in_str(char *str, char c);
char				*ft_strjoin_free(char *s1, char *s2);
char				*ft_strncpy(char *dst, const char *src, size_t n);
int					ft_strrncmp(char *s1, char *s2, int n);
int					ft_charcount(char *str, char c);
char				**ft_dup_matrix(char **matrix);
long				ft_atol(char *str);
t_intl				*intlist_push(int content);
int					intlist_lenght(t_intl **list);
int					intlist_biggest(t_intl **list);
int					intlist_smallest(t_intl **list);
int					intlist_ordered(t_intl **list);
int					intlist_get_average(t_intl **list);
t_intl				*intlist_new(int n);
t_intl				*intlist_lastnode(t_intl **list);
int					intlist_dub_smallest(t_intl **list_a, t_intl **list_b);
int					intlist_ordered_reverse(t_intl **list);
int					ft_matrixlen(char **matrix);
int					ft_strchr_i(const char *s, int c);
int					ft_strchars_i(const char *s, char *set);
char				**ft_extend_matrix(char **in, char *newstr);
int					ft_putmatrix_fd(char **m, int nl, int fd);
int					ft_strcmp(const char *s1, const char *s2);

#endif
