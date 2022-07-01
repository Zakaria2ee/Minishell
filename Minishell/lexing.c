/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:01:22 by zboudair          #+#    #+#             */
/*   Updated: 2022/06/26 19:25:54 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Minishell.h"

t_command	*lexing(char *str)
{
	int			i;
	char		**cmd;
	t_command	*commands;
	t_command	*command_temp;

	replace(str, '|', -2);
	cmd = ft_split(str, -2);
	commands = NULL;
	i = 0;
	while (cmd[i] != '\0')
	{
		command_temp = ft_newcommand(command_temp, &commands);
		get_command(cmd[i], command_temp);
		i++;
	}
	while (i >= 0)
	{
		free(cmd[i]);
		i--;
	}
	free(cmd);
	return (commands);
}

void	replace(char *str, char c1, char c2)
{
	int		i;
	char	opened;

	if (!str)
		return ;
	i = 0;
	opened = 0;
	while (str[i])
	{
		if (!opened && (str[i] == '\"' || str[i] == '\''))
			opened = str[i];
		else if (opened == str[i])
			opened = 0;
		if (!opened && str[i] == c1)
			str[i] = c2;
		i++;
	}
}
