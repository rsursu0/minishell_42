/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbae <wbae@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:56:15 by wbae              #+#    #+#             */
/*   Updated: 2023/03/06 15:19:48 by wbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/wait.h>
# include <unistd.h>
# include <termios.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include "structure.h"

t_env	*g_env;

#endif
