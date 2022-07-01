/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:46:01 by mabenchi          #+#    #+#             */
/*   Updated: 2022/06/24 21:03:18 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static void	print(void *var)
{
	printf("%s\n", var);
}

void	ft_env(t_env *env, char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	if (i > 1)
	{
		print_err_no_dir("env", arg[1]);
		g_util->status = 1;
		return ;
	}
	ft_lstiter(env, &print);
	g_util->status = 0;
}
