/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbae <wbae@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:45:47 by wbae              #+#    #+#             */
/*   Updated: 2023/03/06 15:42:42 by wbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_cmd
{
	struct s_cmd	*next;
	char			*exec_file_path; //실행파일 경로
	char			**av; //실행시 주어질 av
	char			**input_buf; //pipe가 왔을때 이전 수행에서 전달된 값
	char			*output_buf; //수행의 결과가 저장될 값
}	t_cmd;

typedef struct s_env
{
	struct s_env	*next;
	char			*key;
	char			*val;
	int				status;
}	t_env;

typedef struct s_cmd_list
{
	struct s_cmd		*cmd_list;
	struct s_cmd_list	*next_lists;
	char				*first_input;
	int					status;
}	t_cmd_list;

typedef struct s_cmd_container
{
	struct s_cmd_list	*cmd_lists;
	int					status;
}	t_cmd_container;

#endif
