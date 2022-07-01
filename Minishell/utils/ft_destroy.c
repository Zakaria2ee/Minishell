/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:17:29 by zboudair          #+#    #+#             */
/*   Updated: 2022/06/12 19:39:02 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

void	destroy(t_command *command_temp)
{
	t_command	*temp;

	while (command_temp)
	{
		while (command_temp->rdc_token)
		{
			command_temp->rdc_tmp = command_temp->rdc_token;
			command_temp->rdc_token = command_temp->rdc_token->next;
			free(command_temp->rdc_tmp->tkn);
			free(command_temp->rdc_tmp);
		}
		while (command_temp->arg_token)
		{
			command_temp->arg_tmp = command_temp->arg_token;
			command_temp->arg_token = command_temp->arg_token->next;
			free(command_temp->arg_tmp->tkn);
			free(command_temp->arg_tmp);
		}
		temp = command_temp;
		command_temp = command_temp->next;
		free(temp);
	}
}

void	destroy2(t_cmd *cmd)
{
	t_cmd	*temp;
	int		i;

	i = 0;
	while (cmd)
	{
		i = 0;
		temp = cmd;
		cmd = cmd->next;
		while (temp->argv[i])
			i++;
		while (i >= 0)
		{
			free(temp->argv[i]);
			i--;
		}
		free(temp->argv);
		free(temp);
	}
}
