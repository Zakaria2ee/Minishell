/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_to_no_space.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:01:22 by mabenchi          #+#    #+#             */
/*   Updated: 2022/07/01 17:10:08 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

int	ft_strlen_no_space(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			j++;
		i++;
	}
	return (j);
}

char	*line_to_no_space(char *line)
{
	char	*no_space;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen_no_space(line);
	no_space = malloc((j + 1) * sizeof(char));
	if (!no_space)
		exit(103);
	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
		{
			no_space[j] = line[i];
			j++;
		}
		i++;
	}
	no_space[j] = '\0';
	return (no_space);
}