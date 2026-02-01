/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:58:50 by kraoui            #+#    #+#             */
/*   Updated: 2025/12/15 23:21:13 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>

# define MAX_ULL 18446744073709551615ULL
# define MAX_LL 9223372036854775807LL
# define MAX_UI 4294967294U
# define MAX_I 2147483647

//	error messages

# define ERR_MALLOC "malloc failed"
# define ERR_PIPE "pipe failed"
# define ERR_READ "read failed"
# define ERR_FORK "fork failed"
# define ERR_OPEN ": No such file or directory"
# define ERR_DUP2 "dup2 failed"
# define ERR_DUP "dup failed"

// checkers
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

// converters
int		ft_toupper(int c);
int		ft_tolower(int c);

// mem
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

// str
size_t	ft_strlen(const char *s);
size_t	ft_strslen(const char **s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	**ft_split_sp(char const *s);
char	**ft_split_by_one(char const *s, char c);
void	*free_split(char **strs, int i);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin3(const char *s1, const char *s2, const char *s3);
char	*ft_strsjoin(char **strs, char *sep);
char	*ft_strappend(char **s1, const char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// itoa_atoi
char	*ft_itoa(int n);
char	*ft_stoa(size_t num);
int		ft_atoi(const char *str);

// put_fd
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	*ft_puterror(char *msg);

// put
void	ft_putchar(int c);
void	ft_putstr(const char *str, size_t len, int fd);
void	ft_putnbr(long n);

// linked_lists
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// get_next_line
# define BUFFER_SIZE 1

char	*get_next_line(int fd);

// ft_printf

typedef struct s_flags
{
	char	*base;
	int		flag;
	char	fd;
	int		width;
	int		precision;
	int		minus_flag;
	int		zero_flag;
	int		plus_flag;
	int		space_flag;
	int		hash_flag;
}				t_flags;

//		tools
void	ft_putnbr_pf(long n, int sep, t_flags f, int flag);
int		count_snbr(long n, t_flags f);
int		count_nbr(long n);
char	mid_handler(long n, t_flags f);
void	ft_puthex(unsigned long n, int sep, t_flags f, int flag);
int		count_shex(unsigned long n, t_flags f);
int		count_hex(unsigned long n);
//		flags
int		flag_handler(char c, int len, int width, int fd);
void	init_flags(t_flags *f);
int		flag_checker(char flag);
void	flag_filler(const char *flag, int *index, t_flags *f);
int		ft_atoi_pf(const char *str, int *index);
//		support
int		ft_print_char(char c, t_flags f, int flag);
int		ft_print_str(const char *str, t_flags f);
int		ft_print_nbr(long n, t_flags f, int flag);
int		ft_print_hex(unsigned long n, char *base, t_flags f, int flag);
//		main function
int		ft_printf(const char *init, ...);

#endif
