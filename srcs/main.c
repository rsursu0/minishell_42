/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbae <wbae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:33:23 by wbae              #+#    #+#             */
/*   Updated: 2023/03/02 16:50:42 by wbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	main_init()

int	main(int ac, char *av[], char *envp[])
{
	char			*line;
	struct termios	terminal;

	tcgetattr(STDIN_FILENO, &terminal);

	while(1)
	{

	}
	tcsetattr(STDOUT_FILENO, TCSANOW, &terminal);
	return (0);
}
