/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:49:44 by zboudair          #+#    #+#             */
/*   Updated: 2022/07/01 17:30:30 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Minishell.h"

t_cmd	*parsing(t_command *command)
{
	t_cmd	*cmd;
	int		d;

	cmd = ft_locate(command);
	arguments_handler(command, cmd);
	d = herdoc_handler(command, cmd);
	if (!files_herdoc(d, cmd, command))
		return (0);
	ft_files_handler(command, cmd);
	return (cmd);
}

static void	create_nodes(t_cmd **cmd, t_cmd **cmd_temp)
{
	if (*cmd)
	{
		(*cmd_temp)->next = ft_newcmd();
		(*cmd_temp) = (*cmd_temp)->next;
		(*cmd_temp)->in_fd = -1;
		(*cmd_temp)->out_fdl = -1;
		(*cmd_temp)->rdc_check = 0;
		(*cmd_temp)->next = NULL;
	}
	else
	{
		(*cmd_temp) = ft_newcmd();
		*cmd = (*cmd_temp);
		(*cmd)->in_fd = -1;
		(*cmd)->out_fdl = -1;
		(*cmd)->rdc_check = 0;
		(*cmd_temp)->next = NULL;
	}
}

t_cmd	*ft_locate(t_command *command_temp)
{
	t_cmd	*cmd;
	t_cmd	*cmd_temp;
	int		i;

	cmd = NULL;
	cmd_temp = NULL;
	i = 0;
	while (command_temp)
	{
		create_nodes(&cmd, &cmd_temp);
		cmd->id = i;
		command_temp = command_temp->next;
		i++;
	}
	return (cmd);
}

int	test_q(char *line)
{
	char	*no_space;
	char	*err;
	int		herdoc;

	err = NULL;
	no_space = line_to_no_space(line);
	if (no_space[0] && quotes(line, &err)
		&& pipes(no_space, &err))
	{
		free(no_space);
		return (1);
	}
	if (err)
	{
		ft_putstr_fd("Minishell: ", 2);
		ft_putstr_fd(err, 2);
	}
	free(no_space);
	return (0);
}

int	check_fileserrors(t_command *command)
{
	t_command	*temp;

	temp = command;
	while (temp)
	{
		temp->rdc_tmp = temp->rdc_token;
		while (temp->rdc_tmp)
		{
			if (!temp->rdc_tmp->tkn)
			{
				ft_putstr_fd("Minishell: syntax error near unexpected token",
					2);
				if (temp->rdc_tmp->cmd == APPEND)
					ft_putstr_fd("`>>'\n", 2);
				else if (temp->rdc_tmp->cmd == OUTFILE)
					ft_putstr_fd("`>'\n", 2);
				else if (temp->rdc_tmp->cmd == INFILE)
					ft_putstr_fd("`<'\n", 2);
				return (0);
			}
			temp->rdc_tmp = temp->rdc_tmp->next;
		}
		temp = temp->next;
	}
	return (1);
}
