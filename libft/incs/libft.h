/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:39:09 by obelair           #+#    #+#             */
/*   Updated: 2021/06/06 17:15:35 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define FALSE	0
# define TRUE	1
# define B8		"01234567"
# define B10	"0123456789"
# define B16L	"0123456789abcdef"
# define B16U	"0123456789ABCDEF"

# define BUFFER_SIZE 42

/*	==================
	=== Chain List ===
	==================	*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstadd_void(t_list **list, void *new, int back);
int		ft_lstadd_dbl(t_list **list, void **new, size_t size, int back);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), \
			void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

/*	==================
	===   ft_int   ===
	==================	*/

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_intblen(long long n, long long base);
int		ft_uintblen(unsigned long long n, unsigned long long base);
int		*ft_intjoin(int *n1, const int *n2, size_t len_n1, size_t len_n2);

/*	==================
	===   ft_cmp   ===
	==================	*/

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_strisdigit(char *str);
int		ft_max(int n1, int n2);
int		ft_min(int n1, int n2);

/*	==================
	===   ft_str   ===
	==================	*/

char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strichr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, const char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *h, const char *n, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
size_t	ft_word_len(char **str);
char	**ft_word_join(char **s1, char *s2);

/*	==================
	===   ft_put   ===
	==================	*/

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

/*	==================
	===   ft_mem   ===
	==================	*/

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);

/*	===================
	===  ft_printf  ===
	===================	*/

typedef struct s_format
{
	va_list		*ap;
	int			minus;
	int			zero;
	int			hash;
	int			space;
	int			plus;
	int			point;
	char		spec;
	int			wprec;
	int			width;
	int			lenvar;
	char		*base;
	int			fd;
	int			nbprint;
}	t_format;

int		ft_printf(const char *str, ...) __attribute__((format(printf, 1, 2)));
int		ft_scan_str(t_format *tf, const char *str);
void	ft_init_struct(va_list *ap, t_format *tf, int fd);
void	ft_displ_int(t_format *tf, char *base);
void	ft_displ_addr(t_format *tf, char *base);
void	ft_displ_nbr(t_format *tf, unsigned long long val);
void	ft_displ_spc(t_format *tf, int i);
void	ft_displ_zero(t_format *tf, int i);
void	ft_displ_pre(t_format *tf, long long *val);
void	ft_displ_chr(t_format *tf);
void	ft_displ_str(t_format *tf);
void	ft_nptr(t_format *tf);
void	ft_lencmp(t_format *tf, long long val);

/*	===============
	===   gnl   ===
	===============	*/

int		get_next_line(int fd, char **line);

#endif
