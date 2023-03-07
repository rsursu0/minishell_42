/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbae <wbae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:09:28 by wbae              #+#    #+#             */
/*   Updated: 2022/07/23 14:17:03 by wbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t		len;
	char		*arr;

	len = ft_strlen(src);
	arr = malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	arr[0] = '\0';
	while (*src)
		*arr++ = *src++;
	*arr = '\0';
	return (arr - len);
}
