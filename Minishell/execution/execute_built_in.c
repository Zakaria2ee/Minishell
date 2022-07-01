/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_built_in.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 19:26:29 by mabenchi          #+#    #+#             */
/*   Updated: 2022/06/30 14:44:55 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"
#include "../includes/Minishell.h"

int	is_built_in(t_cmd *cmd)
{
	if (!cmd->argv[0])
		return (0);
	if (!ft_strcmp("cd", cmd->argv[0]))
		return (1);
	else if (!ft_strcmp("echo", cmd->argv[0]))
		return (1);
	else if (!ft_strcmp("env", cmd->argv[0]))
		return (1);
	else if (!ft_strcmp("exit", cmd->argv[0]))
		return (1);
	else if (!ft_strcmp("export", cmd->argv[0]))
		return (1);
	else if (!ft_strcmp("unset", cmd->argv[0]))
		return (1);
	else if (!ft_strcmp("pwd", cmd->argv[0]))
		return (1);
	return (0);
}

void	execute_built_in(t_cmd *cmd, t_exe *exe, int to_dup)
{
	dup_fdin_fdout(to_dup, exe);
	if (!ft_strcmp("cd", cmd->argv[0]))
		ft_cd(cmd->argv[1]);
	else if (!ft_strcmp("echo", cmd->argv[0]))
		ft_echo(cmd->argv);
	else if (!ft_strcmp("env", cmd->argv[0]))
		ft_env(g_util->env_lst, cmd->argv);
	else if (!ft_strcmp("exit", cmd->argv[0]))
		ft_exit(cmd->argv);
	else if (!ft_strcmp("export", cmd->argv[0]))
		ft_export(cmd->argv, &g_util->env_lst);
	else if (!ft_strcmp("unset", cmd->argv[0]))
		ft_unset(cmd->argv, &g_util->env_lst, 0);
	else if (!ft_strcmp("pwd", cmd->argv[0]))
		ft_pwd();
	if (to_dup)
	{
		close(0);
		close(1);
		dup(exe->tmpin);
		dup(exe->tmpout);
	}
}

void	fork_exe(t_cmd *cmd, t_exe *exe)
{
	exe->ret = fork();
	if (exe->ret == 0)
		child_work(cmd, exe);
}
