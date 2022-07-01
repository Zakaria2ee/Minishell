/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:11:22 by mabenchi          #+#    #+#             */
/*   Updated: 2022/06/28 18:17:29 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"
#include "../includes/execution.h"

t_env	*is_in_env(t_env *env, char **var_val, char *var, int to_free)
{
	t_env	*tmp;

	tmp = env;
	(void)to_free;
	while (tmp)
	{
		if (!varcmp(var, tmp->var))
		{
			free(var);
			if (var_val)
				free(var_val);
			return (tmp);
		}
		tmp = tmp->next;
	}
	free(var);
	if (var_val)
		free(var_val);
	return (NULL);
}

char	*get_rid_of_plus(char *var)
{
	char	*dup;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (var[i])
	{
		if (var[i] == '+' && var[i + 1] == '=')
			j = 1;
		if (j == 1)
			var[i] = var[i + 1];
		i++;
	}
	return (ft_strdup(var));
}

char	**split_one_eq(char *var)
{
	int		i;
	char	**var_val;
	char	*dup;

	i = 0;
	if (!to_join(var))
		dup = ft_strdup(var);
	else
		dup = get_rid_of_plus(var);
	while (dup[i])
	{
		if (dup[i] == '=')
		{
			dup[i] = -2;
			break ;
		}
		i++;
	}
	i = 0;
	var_val = ft_split(dup, -2);
	free(dup);
	return (var_val);
}

t_env	*norm(char	**var, int i, int *status, t_env **env)
{
	char	**var_val;
	char	*tmp;

	var_val = split_one_eq(var[i]);
	if (test(var_val[0], "export"))
	{
		free(var_val[0]);
		free(var_val[1]);
		free(var_val);
		return ((t_env *)-1);
	}
	if (ft_strchr(var[i], '=') && !var_val[1])
	{
		tmp = ft_strjoin(var[i], "\"\"");
		free(var[i]);
		*status = 0;
		var[i] = tmp;
	}
	else if (var_val[1])
		*status = 1;
	free(var_val[1]);
	return (is_in_env(*env, var_val, var_val[0], 1));
}

int	zero_or_not(char *var)
{
	int	i;
	int	yes;

	i = 0;
	yes = 0;
	while (var[i])
	{
		if (var[i] == '=' && var[i + 1] == '\"')
		{
			yes = 1;
			break ;
		}
		else if (var[i] == '=' && var[i + 1] != '\"')
		{
			yes = 0;
			break ;
		}
		i++;
	}
	return (yes);
}
