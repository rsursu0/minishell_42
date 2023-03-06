/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbae <wbae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:21:29 by wbae              #+#    #+#             */
/*   Updated: 2022/07/25 20:53:23 by wbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *dest, int c, size_t len)
{
	while (len--)
	{
		if (*(unsigned char *)dest == (unsigned char)c)
			return ((void *)dest);
		dest++;
	}
	return (0);
}
