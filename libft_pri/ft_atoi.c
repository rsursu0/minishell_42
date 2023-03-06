/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbae <wbae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:25:39 by wbae              #+#    #+#             */
/*   Updated: 2022/07/22 21:30:55 by wbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nbr)
{
	long	i;
	long	sign;

	i = 0;
	sign = 1;
	while ((*nbr >= 9 && *nbr <= 13) || *nbr == 32)
		nbr++;
	if (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			sign = -1;
		nbr++;
	}
	while (*nbr >= '0' && *nbr <= '9')
	{
		i = i * 10 + (*nbr - 48);
		if (i > 2147483647 && sign == 1)
			return (-1);
		if (i > 2147483648 && sign == -1)
			return (0);
		nbr++;
	}
	return (i * sign);
}
