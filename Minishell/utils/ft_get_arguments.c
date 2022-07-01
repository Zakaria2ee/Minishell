/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:02:22 by zboudair          #+#    #+#             */
/*   Updated: 2022/07/01 17:26:00 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

void	get_arguments(t_command *command_temp, char *str)
{
	int	i;
	int	type;

	i = 0;
	type = 0;
	while (str[i] != '\0')
	{
		skipspace(&i, str);
		if (check_rdc(&i, &type, str) == 1)
		{
			get_arg(&i, str, command_temp, type);
			type = 0;
		}
		skipspace(&i, str);
	}
}

void	get_arg(int *n, char *str, t_command *command_temp, int type)
{
	char	*val;
	int		i;

	i = *n;
	skip_quots(str, &i);
	if (type == 0)
	{
		val = ft_substr(str, *n, i - (*n));
		val = dollar_handler(val);
		if (*val)
		{
			val = quots_handler(val);
			replace2(val, -2, '\'');
			get_arg_token(command_temp);
			command_temp->arg_tmp->tkn = ft_strdup(val);
		}
		free(val);
	}
	*n = i;
}

int	check_rdc(int *n, int *type, char *str)
{
	if (str[*n] == '>' && str[*n + 1] == '>')
	{
		*n += 2;
		*type = 1;
	}
	else if (str[*n] == '<' && str[*n + 1] == '<')
	{
		*n += 2;
		*type = 2;
	}
	else if (str[*n] == '>')
	{
		(*n)++;
		*type = 3;
	}
	else if (str[*n] == '<')
	{
		(*n)++;
		*type = 4;
	}
	else
		return (1);
	return (0);
}
