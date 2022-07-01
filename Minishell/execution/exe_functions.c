/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:58:48 by mabenchi          #+#    #+#             */
/*   Updated: 2022/06/30 14:44:09 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"
#include "../includes/Minishell.h"

void	free_for_me(char **split, char *cmd_one)
{
	int	i;

	i = -1;
	free(cmd_one);
	if (split)
	{
		while (split[++i])
			free(split[i]);
		free(split);
	}
}

static char	**split_all_paths(void)
{
	char	*path;
	char	**split;

	path = split_to_path();
	split = ft_split(path, ':');
	free(path);
	return (split);
}

char	*get_cmd_path(t_cmd *cmd, int i)
{
	char	**split;
	char	*cmd_one;
	char	*path;

	if (!cmd->argv[0] || !cmd->argv[0][0])
		return ((char *)-1);
	if (ft_strchr(cmd->argv[0], '/'))
		return (cmd->argv[0]);
	split = split_all_paths();
	cmd_one = ft_strjoin("/", cmd->argv[0]);
	while (split && split[++i])
	{
		path = ft_strjoin(split[i], cmd_one);
		if (!access(path, X_OK))
		{
			free_for_me(split, cmd_one);
			return (path);
		}
		free(path);
	}
	free_for_me(split, cmd_one);
	if (is_built_in(cmd))
		return (cmd->argv[0]);
	g_util->status = 127;
	return (NULL);
}

int	**pipes_create(int size)
{
	int	i;
	int	**pipe_fd;

	i = 0;
	if (size == 1)
		return (NULL);
	pipe_fd = (int **)malloc((size - 1) * sizeof(int *));
	if (!pipe_fd)
		exit(2);
	while (i < size - 1)
	{
		pipe_fd[i] = (int *)malloc(2 * sizeof(int));
		if (!pipe_fd[i])
			exit(2);
		pipe(pipe_fd[i]);
		i++;
	}
	return (pipe_fd);
}

void	close_all(int **pipe_fd, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		close(pipe_fd[i][0]);
		close(pipe_fd[i][1]);
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		free(pipe_fd[i]);
		i++;
	}
	free (pipe_fd);
}
