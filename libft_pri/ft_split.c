/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbae <wbae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:18:51 by wbae              #+#    #+#             */
/*   Updated: 2022/11/22 15:29:35 by wbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_malloc_free(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

static int	len_cnt(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

static void	mv_if_charset(const char **s, char c)
{
	while (**s && **s == c)
		(*s)++;
}

static int	wd_cnt(const char *str, char c)
{
	int	i;
	int	wd;

	i = 0;
	wd = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != '\0')
			wd++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (wd);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**arr;

	if (!s)
		return (0);
	arr = (char **)malloc(sizeof(char *) * (wd_cnt(s, c) + 1));
	if (!arr)
		return (0);
	i = 0;
	mv_if_charset(&s, c);
	while (*s)
	{
		j = 0;
		arr[i] = malloc(sizeof(char) * len_cnt(s, c) + 1);
		if (!arr[i])
			return (ft_malloc_free(arr));
		while (*s && *s != c)
			arr[i][j++] = *s++;
		arr[i][j] = '\0';
		i++;
		mv_if_charset(&s, c);
	}
	arr[i] = 0;
	return (arr);
}

#include <stdio.h>

int main()
{
	char **s;
	char *str = "ao bo co do eo fo go";
	int i = 0;

	s = ft_split(str, ' ');
	while (s[i])
	{
		printf("%s\n", s[i]);
		i++;
	}
}
