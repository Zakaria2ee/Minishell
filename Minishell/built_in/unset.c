/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:38:08 by mabenchi          #+#    #+#             */
/*   Updated: 2022/06/25 21:52:39 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

int	test(char *var, char *command)
{
	int	i;

	i = 1;
	if (var)
	{			
		if ((!ft_isalpha(var[0]) || var[0] == '=') && var[0] != '_')
		{
			print_err_unset(var, command);
			return (1);
		}
		while (var[i])
		{
			if (var[i] != '_' && !ft_isalpha(var[i]) && !ft_isdigit(var[i]))
			{
				if (!var[i + 1] && var[i] == '+')
					return (0);
				print_err_unset(var, command);
				return (1);
			}
			i++;
		}
	}
	return (0);
}

int	varcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] && s1[i] && s1[i] == s2[i] && s2[i] != '=')
		i++;
	if (s2[i] == '=' || !s2[i])
		return (0);
	return (1);
}

static void	delete(char *var_eq, t_env **tmp, t_env **prev)
{
	while (*tmp)
	{
		if (!varcmp(var_eq, (*tmp)->var))
		{
			(*prev)->next = (*tmp)->next;
			free((*tmp)->var);
			free(*tmp);
			break ;
		}
		*prev = *tmp;
		*tmp = (*tmp)->next;
	}
}

void	del_var(t_env **env, char *var)
{
	t_env	*tmp;
	t_env	*prev;

	tmp = *env;
	prev = tmp;
	if (tmp)
	{
		if (!varcmp(var, tmp->var))
		{
			*env = tmp->next;
			free(tmp->var);
			free(tmp);
			g_util->status = 0;
		}
		else
			delete(var, &tmp, &prev);
	}
}

void	ft_unset(char **var, t_env **env, int i)
{
	t_env	*tmp;
	t_env	*prev;
	char	**split;

	while (var[++i])
	{
		split = ft_split(var[i], '=');
		if (test(split[0], "unset"))
		{
			g_util->status = 1;
			return ;
		}
		del_var(env, var[i]);
		free(split[0]);
		free(split[1]);
		free(split);
	}
	g_util->status = 0;
}
