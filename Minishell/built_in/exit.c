/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:46:34 by mabenchi          #+#    #+#             */
/*   Updated: 2022/06/30 15:05:41 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

int	str_isdigit(char *arg)
{
	int	i;

	i = 0;
	if (arg && !ft_isdigit(arg[0]) && arg[0] != '-' && arg[0] != '+')
		return (0);
	while (arg[++i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
	}
	return (1);
}

void	ft_exit(char **args)
{
	int	i;
	int	ret;

	ret = -1;
	i = 0;
	if (!args[1])
	{
		printf("exit\n");
		exit(g_util->status);
	}
	printf("exit\n");
	while (args[i])
		i++;
	if (!str_isdigit(args[1]))
		ft_putstr_fd("Minishell: exit: numeric argument required\n", 2);
	else if (i > 2)
	{
		ft_putstr_fd("Minishell: exit: too many arguments\n", 2);
		g_util->status = 1;
		return ;
	}
	else
		ret = ft_atoi(args[1]);
	exit(ret);
}
