/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:01:28 by mabenchi          #+#    #+#             */
/*   Updated: 2022/06/30 15:06:22 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/execution.h"
#include "includes/Minishell.h"

static void	init(t_cmd *cmd, t_exe *exe)
{
	exe->tmpin = dup(0);
	exe->tmpout = dup(1);
	exe->size_lst = ft_lstsize(cmd);
	exe->pipe_fd = pipes_create(exe->size_lst);
}

static void	fdin_fdout(t_cmd *cmd, t_exe *exe, int i)
{	
	exe->fdin = 0;
	exe->fdout = 1;
	if (cmd->in_fd > 0)
		exe->fdin = cmd->in_fd;
	else if (i > 0)
		exe->fdin = exe->pipe_fd[i - 1][0];
	if (cmd->out_fdl > 0)
		exe->fdout = cmd->out_fdl;
	else if (cmd->next)
		exe->fdout = exe->pipe_fd[i][1];
}

void	child_work(t_cmd *cmd, t_exe *exe)
{
	if (!exe->path)
		exit(127);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (exe->fdin != STDIN_FILENO)
		dup2(exe->fdin, 0);
	if (exe->fdout != STDOUT_FILENO)
		dup2(exe->fdout, 1);
	close_all(exe->pipe_fd, exe->size_lst);
	if (!is_built_in(cmd))
	{
		if (cmd->argv[0] && cmd->argv[0][0] != '\0')
		{
			execve(exe->path, cmd->argv, g_util->env);
			perror("Minishell");
		}
	}
	else
		execute_built_in(cmd, exe, 0);
	if (exe->path == (char *)-1)
		exit(0);
	exit(1);
}

void	while_loop_exe(t_cmd *cmd, t_exe *exe)
{
	int	i;

	i = 0;
	while (cmd)
	{
		if (cmd->argv[0] && cmd->out_fdl != -2 && cmd->in_fd != -2)
		{
			fdin_fdout(cmd, exe, i);
			exe->path = get_cmd_path(cmd, -1);
			if (exe->path == (char *) -1 || !exe->path)
			{
				print_err_get_cmd(cmd->argv[0]);
				break ;
			}
			if (is_built_in(cmd) && exe->size_lst == 1)
				execute_built_in(cmd, exe, 1);
			else if (exe->path)
				fork_exe(cmd, exe);
			if (exe->path && exe->path != cmd->argv[0]
				&& exe->path != (char *)-1)
				free(exe->path);
		}
		i++;
		cmd = cmd->next;
	}
}

void	execution(t_cmd *cmd)
{
	t_exe	exe;

	exe.ret = 0;
	init(cmd, &exe);
	while_loop_exe(cmd, &exe);
	close_all(exe.pipe_fd, exe.size_lst);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (exe.ret && !g_util->status)
	{
		waitpid(exe.ret, &g_util->status, 0);
		if (WIFEXITED(g_util->status))
			g_util->status = WEXITSTATUS(g_util->status);
		else if (g_util->status == 3 || g_util->status == 2)
			g_util->status = 128 + (g_util->status);
	}
	while (wait(NULL) != -1)
	{
	}
	signal(SIGINT, signal_routine);
	signal(SIGQUIT, SIG_IGN);
}
