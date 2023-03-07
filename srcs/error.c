/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbae <wbae@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:37:37 by wbae              #+#    #+#             */
/*   Updated: 2023/03/06 15:37:52 by wbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	syntax_error(char *str, int code, int flag)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	if (!flag)
		g_env->status = code;
	if (flag)
		exit(code);
}

void	print_error(char *str, int code, int flag)
{
	ft_putstr_fd("minishell: ", 2);
	perror(str);
	if (!flag)
		g_env->status = code;
	if (flag)
		exit(code);
}

void	cmd_error(char *str, int code, int flag)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": command not found\n", 2);
	if (!flag)
		g_env->status = code;
	if (flag)
		exit(code);
}
