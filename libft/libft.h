/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbae <wbae@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:11:47 by wbae              #+#    #+#             */
/*   Updated: 2023/03/06 15:27:28 by wbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

//part 1//
void	ft_bzero(void *ptr, size_t size);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(char *s);
void	*ft_memchr(const void *dest, int c, size_t len);
int		ft_memcmp(const void *str1, const void *str2, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t len);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memset(void *dest, int value, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_strlen(const char *str);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strnstr(const char *big, const char *small, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

//part 2//
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int nbr, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
int		ft_atoi(const char *nbr);

//bonus part//
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));//

#endif
