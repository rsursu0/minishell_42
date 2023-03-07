/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbae <wbae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:55:51 by wbae              #+#    #+#             */
/*   Updated: 2022/07/25 20:00:21 by wbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*node;
	void	*tmp;

	if (!lst || !f)
		return (0);
	result = NULL;
	while (lst)
	{
		tmp = f(lst->content);
		node = ft_lstnew(tmp);
		if (!node)
		{
			if (tmp)
				free(tmp);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, node);
		lst = lst->next;
	}
	return (result);
}
