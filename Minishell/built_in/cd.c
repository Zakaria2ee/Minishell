/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:03:44 by mabenchi          #+#    #+#             */
/*   Updated: 2022/06/30 15:15:22 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"
#include "../includes/execution.h"

void	ft_cd(char *path)
{
	char	**split;
	int		to_free;

	to_free = 0;
	if (!find_pwd("OLDPWD=") && !g_util->firstunset)
	{
		g_util->firstunset = 1;
		ft_lstadd_back(&g_util->env_lst, ft_lst_new(ft_strdup("OLDPWD=\"\"")));
		ft_lstlast(g_util->env_lst)->from_export = 1;
		ft_lstlast(g_util->env_lst)->status = 0;
	}
	if (!path || (path && path[0] == '~'))
		cd_no_arg(&path, &to_free, ft_strdup("HOME"));
	else if (g_util->oldpwd_is_set && path[0] == '-')
		cd_no_arg(&path, &to_free, ft_strdup("OLDPWD"));
	if (chdir(path))
	{
		g_util->status = 1;
		print_err_no_dir("cd", path);
	}
	else
		g_util->status = 0;
	change_pwd(-1);
	if (path && to_free)
		free(path);
}
