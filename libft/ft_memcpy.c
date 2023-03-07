/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbae <wbae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:58:11 by wbae              #+#    #+#             */
/*   Updated: 2022/07/22 17:47:22 by wbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char	*new_dest;
	unsigned char	*new_src;

	if (!dest && !src)
		return (0);
	new_dest = dest;
	new_src = (unsigned char *)src;
	while (len-- > 0)
		*new_dest++ = *new_src++;
	return (dest);
}
