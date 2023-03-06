/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbae <wbae@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:33:23 by wbae              #+#    #+#             */
/*   Updated: 2023/03/06 14:48:22 by wbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	main_init(int ac, char *av[])
{
	struct termios	term;

	if (ac != 1)
		exit_error("Wrong input!");
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDOUT_FILENO, TCSANOW, &term);
	(void)ac;
	(void)av;
}

int	main(int ac, char *av[], char *envp[])
{
	char			*line;
	struct termios	terminal;

	tcgetattr(STDIN_FILENO, &terminal);
	main_init(ac, av);
	while (1)
	{
		line = readline("minishell $> ");
	}
	tcsetattr(STDOUT_FILENO, TCSANOW, &terminal);
	return (0);
}
