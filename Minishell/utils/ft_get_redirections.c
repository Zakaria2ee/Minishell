/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:05:05 by zboudair          #+#    #+#             */
/*   Updated: 2022/06/17 14:59:34 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

void	get_redirections(t_command *command_temp, char *str)
{
	int	i;
	int	quots;

	i = 0;
	quots = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == '\'' || str[i] == '"') && quots == 0)
			quots = str[i];
		else if (quots && str[i] == quots)
			quots = 0;
		if (str[i] == '>' && str[i + 1] == '>' && quots == 0)
			get_appendfile(&i, str, command_temp);
		else if (str[i] == '<' && str[i + 1] == '<' && !quots)
			get_herdoclimiter(&i, str, command_temp);
		else if (str[i] == '>' && quots == 0)
			get_outfile(&i, str, command_temp);
		else if (str[i] == '<' && quots == 0)
			get_infile(&i, str, command_temp);
		i++;
	}
}
