/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:59:41 by zboudair          #+#    #+#             */
/*   Updated: 2022/07/01 16:46:01 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

char	*expand(t_env	*env_lst, char *var)
{
	int		j;
	int		quot;
	int		start;
	char	*val;

	j = ft_strlen(var);
	quot = 0;
	start = 0;
	while (env_lst)
	{
		if (!ft_memcmp(var, env_lst->var, j) && env_lst->var[j] == '=')
		{
			j++;
			start = j;
			skip_token(env_lst->var, &j, &quot);
			free(var);
			val = ft_substr(env_lst->var, start, (j - start));
			replace2(val, '\'', -2);
			return (val);
		}
		env_lst = env_lst->next;
	}
	free(var);
	return (0);
}

void	skip_token(char *str, int *j, int *quot)
{
	while (str[*j])
		(*j)++;
}
