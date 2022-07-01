/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:16:38 by zboudair          #+#    #+#             */
/*   Updated: 2022/07/01 17:18:58 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

void	arguments_handler(t_command *command, t_cmd *cmd)
{
	t_command	*temp;
	t_cmd		*cmd_temp;
	int			i;
	int			len;

	temp = command;
	cmd_temp = cmd;
	while (temp)
	{
		i = 0;
		len = arg_len(temp);
		cmd_temp->argv = (char **)malloc(sizeof(char *) * (len + 1));
		cmd_temp->argv[len] = 0;
		temp->arg_tmp = temp->arg_token;
		while (temp->arg_tmp)
		{
			cmd_temp->argv[i] = ft_strdup(temp->arg_tmp->tkn);
			temp->arg_tmp = temp->arg_tmp->next;
			i++;
		}
		temp = temp->next;
		cmd_temp = cmd_temp->next;
	}
}

int	arg_len(t_command *command)
{
	t_command	*command_temp;
	int			i;

	command_temp = command;
	i = 0;
	command_temp->arg_tmp = command_temp->arg_token;
	while (command_temp->arg_tmp)
	{
		i++;
		command_temp->arg_tmp = command_temp->arg_tmp->next;
	}
	return (i);
}
