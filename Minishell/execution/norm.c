/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:00:24 by mabenchi          #+#    #+#             */
/*   Updated: 2022/06/24 21:43:46 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"
#include "../includes/execution.h"

void	dup_fdin_fdout(int to_dup, t_exe *exe)
{
	if (to_dup)
	{
		if (exe->fdin != STDIN_FILENO)
			dup2(exe->fdin, 0);
		if (exe->fdout != STDOUT_FILENO)
			dup2(exe->fdout, 1);
	}
}

char	*split_to_path(void)
{
	char	**split_tr;
	char	*path;
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = g_util->env_lst;
	path = NULL;
	while (tmp)
	{
		if (ft_memcmp("PATH", tmp->var, 4) == 0)
			break ;
		tmp = tmp->next;
	}
	if (tmp)
	{
		split_tr = ft_split(tmp->var, '=');
		path = split_tr[1];
		free(split_tr[0]);
		free(split_tr);
	}
	return (path);
}
