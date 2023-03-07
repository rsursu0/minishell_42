/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbae <wbae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:09:50 by wbae              #+#    #+#             */
/*   Updated: 2022/07/22 17:50:56 by wbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_nbr(int nbr, int fd)
{
	if (nbr >= 10)
		ft_nbr(nbr / 10, fd);
	write(fd, &"0123456789"[nbr % 10], 1);
}

void	ft_putnbr_fd(int nbr, int fd)
{
	if (fd < 0)
		return ;
	if (nbr == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr *= -1;
	}
	ft_nbr(nbr, fd);
}
