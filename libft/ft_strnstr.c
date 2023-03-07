/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbae <wbae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:19:06 by wbae              #+#    #+#             */
/*   Updated: 2022/07/22 17:47:35 by wbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	i;

	if (!*small)
		return ((char *)big);
	while (*big != '\0' && len > 0)
	{
		i = 0;
		while (*(big + i) == *(small + i) && i < len)
		{
			i++;
			if (*(small + i) == '\0')
				return ((char *)big);
		}
		big++;
		len--;
	}
	return (0);
}
