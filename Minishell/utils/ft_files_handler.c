/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:39:40 by zboudair          #+#    #+#             */
/*   Updated: 2022/07/01 17:19:05 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

void	ft_files_handler(t_command *command, t_cmd *cmd)
{
	t_command	*temp;
	int			file;
	int			fd;

	temp = command;
	while (temp)
	{
		file = 0;
		fd = 0;
		temp->rdc_tmp = temp->rdc_token;
		ft_check(temp, cmd, &file, &fd);
		if (g_util->cond == 0 && file)
			cmd->in_fd = file;
		if (fd)
			cmd->out_fdl = fd;
		temp = temp->next;
		cmd = cmd->next;
	}
}

void	ft_check(t_command *temp, t_cmd *cmd, int *file, int *fd)
{
	while (temp->rdc_tmp)
	{
		if (temp->rdc_tmp->cmd == HERDOC || temp->rdc_tmp->cmd == INFILE)
		{
			if (!ft_check1(temp, cmd, file))
				break ;
		}
		else if (temp->rdc_tmp->cmd == APPEND || temp->rdc_tmp->cmd == OUTFILE)
		{
			if (!ft_check2(temp, cmd, fd))
				break ;
		}
		temp->rdc_tmp = temp->rdc_tmp->next;
	}
}

int	ft_check1(t_command *temp, t_cmd *cmd, int*file)
{
	(void)cmd;
	if (temp->rdc_tmp->cmd == HERDOC)
		g_util->cond = 1;
	if (temp->rdc_tmp->cmd == INFILE)
	{
		if (!*temp->rdc_tmp->tkn)
		{
			ft_putstr_fd("Minishell: ambiguous redirect\n", 2);
			return (0);
		}
		*file = open(temp->rdc_tmp->tkn, O_RDONLY, 0777);
		if (*file == -1)
		{
			*file = -2;
			print_err_ambiguous(temp->rdc_tmp->tkn);
			return (0);
		}
		g_util->cond = 0;
	}
	else if (!*temp->rdc_tmp->tkn)
	{
		cmd->in_fd = -2;
		return (0);
	}
	return (1);
}

int	ft_check2(t_command *temp, t_cmd *cmd, int *fd)
{
	if (!ft_check3(temp, cmd))
		return (0);
	if (temp->rdc_tmp->cmd == OUTFILE)
	{
		*fd = open(temp->rdc_tmp->tkn, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (*fd == -1)
		{
			print_err_ambiguous(temp->rdc_tmp->tkn);
			cmd->out_fdl = -1;
			return (0);
		}
	}
	else if (temp->rdc_tmp->cmd == APPEND)
	{
		*fd = open(temp->rdc_tmp->tkn, O_CREAT | O_APPEND | O_RDWR, 0644);
		if (*fd == -1)
		{
			cmd->out_fdl = -1;
			print_err_ambiguous(temp->rdc_tmp->tkn);
			return (0);
		}
	}
	return (1);
}

int	ft_check3(t_command *temp, t_cmd *cmd)
{
	if (!*temp->rdc_tmp->tkn)
	{
		ft_putstr_fd("Minishell: ambiguous redirect\n", 2);
		cmd->out_fdl = -2;
		return (0);
	}
	return (1);
}
