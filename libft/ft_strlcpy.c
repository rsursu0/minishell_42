/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbae <wbae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:44:37 by wbae              #+#    #+#             */
/*   Updated: 2022/07/22 17:47:31 by wbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	while ((i < src_len) && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (src_len);
}
