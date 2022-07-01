/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:43:57 by mabenchi          #+#    #+#             */
/*   Updated: 2022/06/26 16:45:02 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static int	n_flag(char **arg, int *nl)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (arg[i])
	{
		j = 1;
		if (arg[i][0] == '-' && arg[i][1] == 'n')
		{
			while (arg[i][j] && arg[i][j] == 'n')
				j++;
			if (!arg[i][j])
				*nl = 0;
			else
				break ;
		}
		else
			break ;
		i++;
	}
	return (i);
}

void	ft_echo(char **arg)
{
	int	i;
	int	nl;

	nl = 1;
	i = n_flag(arg, &nl);
	while (arg[i])
	{
		ft_putstr_fd(arg[i], 1);
		if (arg[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (nl)
		ft_putstr_fd("\n", 1);
	g_util->status = 0;
}
