/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbae <wbae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:39:00 by wbae              #+#    #+#             */
/*   Updated: 2022/07/22 17:47:13 by wbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int	i;

	if (n < 0)
	{
		i = 1;
		n *= -1;
	}
	else
		i = 0;
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		sign;
	int		n_len;

	sign = 1;
	if (n < 0)
		sign = -1;
	n_len = ft_nbrlen(n);
	ret = malloc(sizeof(char) * (n_len + 1));
	if (!ret)
		return (0);
	ret[n_len] = '\0';
	n_len--;
	while (n / 10 != 0)
	{
		ret[n_len] = ft_abs(n % 10) + '0';
		n = ft_abs(n / 10);
		n_len--;
	}
	ret[n_len] = ft_abs(n) + '0';
	if (sign == -1)
		ret[0] = '-';
	return (ret);
}
