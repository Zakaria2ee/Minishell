/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_q.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 09:18:53 by mabenchi          #+#    #+#             */
/*   Updated: 2022/07/01 16:35:34 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h" 

int	quotes(char *line, char **err)
{
	int	i;
	int	opened;

	i = 0;
	opened = 0;
	while (line[i])
	{
		if (!opened && (line[i] == '"' || line[i] == '\''))
			opened = line[i];
		else if (opened && line[i] == opened)
			opened = 0;
		i++;
	}
	if (opened)
	{
		if (opened == '"')
			*err = "a dquote is open\n";
		else
			*err = "a quote is open\n";
		return (0);
	}
	return (1);
}

int	pipes(char *no_space, char **err)
{
	int	i;
	int quots;

	i = 0;
	quots = 0;
	if (no_space[0] == '|')
	{
		*err = "Error pipe in the beginning of the command line\n";
		return (0);
	}
	while (no_space[i])
	{
		if(!quots && (no_space[i] == '\'' || no_space[i] == '"'))
			quots = no_space[i];
		else if(quots && quots == no_space[i])
			quots = 0;
		if (!quots && no_space[i] == '|' && (!no_space[i + 1] || no_space[i + 1] == '|'))
		{
			*err = "Error pipe must have a command after\n";
			return (0);
		}
		i++;
	}
	return (1);
}

int	files_herdoc(int d, t_cmd *cmd, t_command *command)
{
	if (!d)
	{
		destroy2(cmd);
		return (0);
	}
	else if (d == 1)
	{
		ft_putstr_fd("Minishell: syntax error near unexpected token `<<'\n", 2);
		destroy2(cmd);
		return (0);
	}
	else if (d == 2)
	{
		if (!check_fileserrors(command))
		{
			destroy2(cmd);
			return (0);
		}
	}
	return (1);
}
