/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:37:15 by mabenchi          #+#    #+#             */
/*   Updated: 2022/06/28 18:30:13 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

int	to_join(char *var)
{
	int	i;

	i = 0;
	while (var[i])
	{
		if (var[i] == '+' && var[i + 1] == '=')
			return (1);
		if (var[i] == '=')
			return (0);
		i++;
	}
	return (0);
}

void	ft_pwd(void)
{
	char	cwd[1024];

	getcwd(cwd, sizeof(cwd));
	printf("%s\n", cwd);
	g_util->status = 0;
}
