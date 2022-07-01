/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_herdoc_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:05:25 by zboudair          #+#    #+#             */
/*   Updated: 2022/07/01 17:31:12 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h" 

static int	while_loop(char *str, t_command *command)
{
	while (str)
	{
		if (!ft_strcmp(str, command->rdc_tmp->tkn))
		{
			free(str);
			break ;
		}
		if (!g_util->herdoc_expand)
			str = dollar_handler(str);
		write(g_util->fd[1], str, ft_strlen(str));
		free(str);
		str = readline("herdoc> ");
		write(g_util->fd[1], "\n", 1);
		if (ft_freeing(str) == 0)
			return (0);
		else if (ft_freeing(str) == 1)
			break ;
		if (!ft_strcmp(str, command->rdc_tmp->tkn))
		{
			free(str);
			break ;
		}
	}
	return (1);
}

static int	inside_heredoc(char *str, t_command *command, t_cmd *cmd)
{
	pipe(g_util->fd);
	g_util->herdoc = 1;
	str = readline("herdoc> ");
	if (!while_loop(str, command))
		return (0);
	if (g_util->signal_status == 2)
	{
		dup(g_util->dup_line);
		g_util->signal_status = 0;
		g_util->herdoc = 0;
		return (0);
	}
	close(g_util->fd[1]);
	cmd->in_fd = g_util->fd[0];
	g_util->herdoc = 0;
	return (1);
}

int	herdoc_handler(t_command *command, t_cmd *cmd)
{
	char	*str;

	str = NULL;
	while (command)
	{
		command->rdc_tmp = command->rdc_token;
		while (command->rdc_tmp)
		{
			if (!command->rdc_tmp->tkn && command->rdc_tmp->cmd == HERDOC)
				return (1);
			else if (!command->rdc_tmp->tkn)
				return (2);
			if (command->rdc_tmp->cmd == HERDOC)
			{
				if (!inside_heredoc(str, command, cmd))
					return (0);
			}
			command->rdc_tmp = command->rdc_tmp->next;
		}
		command = command->next;
		cmd = cmd->next;
	}
	return (2);
}

int	ft_freeing(char *str)
{
	if (!str)
	{
		g_util->herdoc = 0;
		if (g_util->signal_status == 2)
		{
			dup(g_util->dup_line);
			g_util->signal_status = 0;
			free(str);
			return (0);
		}
		else
		{
			free(str);
			return (1);
		}
	}
	return (2);
}

int	check_quots(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
			return (1);
		i++;
	}
	return (0);
}
