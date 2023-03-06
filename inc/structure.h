/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbae <wbae@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:45:47 by wbae              #+#    #+#             */
/*   Updated: 2023/03/06 14:29:31 by wbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef enum e_type
{
	cmd,
	red,
	pip
}	t_type;

typedef struct s_cmd
{
	struct s_cmd	*next;
	char			*exec_file_path;
	char			**env;
	char			**av;
	char			**input_buf;
	char			*output_buf;
}	t_cmd;

typedef struct s_cmd_list
{
	struct s_cmd	*cmd_list;
	char			*first_input;
	int				status;
}	t_cmd_list;

#endif
