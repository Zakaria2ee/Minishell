/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:28:59 by mabenchi          #+#    #+#             */
/*   Updated: 2022/06/26 16:43:20 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"
#include "../includes/Minishell.h"

t_env	*find_pwd(char *var_name)
{
	t_env	*tmp;
	char	*no_eq;
	int		i;

	tmp = g_util->env_lst;
	no_eq = malloc(sizeof(var_name) - 1);
	i = 0;
	while (var_name[i] && var_name[i] != '=')
	{
		no_eq[i] = var_name[i];
		i++;
	}
	while (tmp)
	{
		if (!varcmp(no_eq, tmp->var))
			break ;
		tmp = tmp->next;
	}
	free(no_eq);
	return (tmp);
}

void	replace_var(char *var_name, char *path)
{
	t_env	*tmp;
	char	*var;

	tmp = find_pwd(var_name);
	if (!tmp)
		return ;
	free(tmp->var);
	if (!path)
	{
		var = ft_strdup(var_name);
		tmp->var = ft_strjoin(var, "\"\"");
	}
	else
	{
		var = ft_strjoin(var_name, path);
		tmp->var = ft_strdup(var);
	}
	if (var)
		free(var);
}

void	p(t_env *tmp, char *path)
{
	char	**split;

	split = ft_split(tmp->var, '=');
	replace_var("OLDPWD=", split[1]);
	if (split)
	{
		free(split[0]);
		free(split[1]);
		free(split);
	}
	replace_var("PWD=", path);
}

void	change_pwd(int i)
{
	t_env	*tmp;
	char	*path;
	char	**split;
	char	cwd[1024];

	getcwd(cwd, sizeof(cwd));
	path = malloc(ft_strlen(cwd) + 1);
	while (cwd[++i])
		path[i] = cwd[i];
	path[i] = '\0';
	tmp = find_pwd("PWD=");
	if (tmp)
		p(tmp, path);
	else
		replace_var("OLDPWD=", NULL);
	g_util->oldpwd_is_set = 1;
	free(path);
}

void	cd_no_arg(char **path, int *to_free, char *var_name)
{
	char	*path2;
	char	**split;
	char	*expanded;
	t_env	*tmp;

	*to_free = 1;
	tmp = is_in_env(g_util->env_lst, NULL, var_name, 1);
	if (tmp)
		path2 = tmp->var;
	else
	{
		*path = NULL;
		return ;
	}
	split = ft_split(path2, '=');
	path2 = split[1];
	if (*path)
		expanded = ft_strjoin(path2, &path[0][1]);
	else
		expanded = ft_strdup(path2);
	free(split[0]);
	free(split);
	if (path2)
		free(path2);
	*path = expanded;
}
