/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbae <wbae@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:33:23 by wbae              #+#    #+#             */
/*   Updated: 2023/03/06 20:41:03 by wbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	main_init(int ac, char *av[], char *envp[])
{
	struct termios	term;

	if (ac != 1)
		print_error("argument input error", 126, 1);
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDOUT_FILENO, TCSANOW, &term);
	set_sig();
}

int	main(int ac, char *av[], char *envp[])
{
	char			*line;
	struct termios	terminal;

	tcgetattr(STDIN_FILENO, &terminal);
	main_init(ac, av, envp);
	while (1)
	{
		line = readline("minishell $ ");
		if (!line)
			break ;
		if (*line != '\0')
			add_history(line);
		if (*line != '\0' && !ft_isspace(line))
		{
			//동작부
		}
		free(line);
	}
	tcsetattr(STDOUT_FILENO, TCSANOW, &terminal);
	return (0);
}
