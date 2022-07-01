/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quots_hundler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:10:25 by zboudair          #+#    #+#             */
/*   Updated: 2022/07/01 17:18:30 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

char	*quots_handler(char *val)
{
	char	quots;
	int		j;
	int		i;

	if (!val)
		return (0);
	j = 0;
	i = -1;
	quots = 0;
	while (val[++i])
	{
		if (quots && val[i] == quots)
			quots = 0;
		else if ((val[i] == '\'' || val[i] == '"') && !quots)
			quots = val[i];
		else
			val[j++] = val[i];
	}
	val[j] = 0;
	return (val);
}
