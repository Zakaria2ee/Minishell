/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:00:23 by mabenchi          #+#    #+#             */
/*   Updated: 2022/06/28 18:30:19 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"
#include "../includes/execution.h"

static void	print(void *var)
{
	int		i;
	char	*cast;
	int		equal;

	i = 0;
	equal = 0;
	if (!var)
		return ;
	cast = (char *)var;
	printf("declare -x ");
	while (cast[i])
	{
		if (cast[i] == '=')
			equal++;
		if (i && cast[i - 1] == '=' && cast[i] != '\"' && equal == 1)
			printf("\"");
		printf("%c", cast[i]);
		if (!cast[i + 1] && cast[i] != '\"' && equal >= 1)
			printf("\"");
		i++;
	}
	printf("\n");
}

int	while_loop_export(char **var, t_env **env)
{
	int		i;
	t_env	*var_node;
	int		status;
	int		join;

	i = 0;
	status = -1;
	while (var[++i])
	{
		join = to_join(var[i]);
		if (var[i][0] == '\0' || var[i][0] == '=')
		{
			print_err_unset(var[i], "export");
			g_util->status = 1;
			break ;
		}
		var_node = norm(var, i, &status, env);
		if (!add_var(var_node, status, var[i], join))
			return (0);
	}
	return (1);
}

void	join_to_var(t_env *var_node, char *var)
{
	char	**split;
	int		i;
	int		yes;

	i = 0;
	yes = 0;
	yes = zero_or_not(var_node->var);
	split = split_one_eq(var);
	if (yes)
		var_node->var = ft_strdup(var);
	else
		var_node->var = ft_strjoin(var_node->var, split[1]);
	free(split[0]);
	free(split[1]);
	free(split);
}

int	add_var(t_env *var_node, int status, char *var, int join)
{
	char	*tmp;
	t_env	**env;
	char	**split;

	env = &g_util->env_lst;
	if (!var_node)
	{
		ft_lstadd_back(env, ft_lst_new(ft_strdup(var)));
		ft_lstlast(*env)->from_export = 1;
		ft_lstlast(*env)->status = status;
	}
	else if (var_node < 0)
		return (0);
	else if (status >= 0)
	{
		tmp = var_node->var;
		if (!join)
			var_node->var = ft_strdup(var);
		else
			join_to_var(var_node, var);
		free(tmp);
	}
	return (1);
}

void	ft_export(char **var, t_env **env)
{
	if (!var[1])
	{
		ft_lstiter(*env, &print);
		return ;
	}
	if (while_loop_export(var, env))
		g_util->status = 1;
	else
		g_util->status = 0;
}
