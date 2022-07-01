/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_redirectionfile.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 13:12:20 by zboudair          #+#    #+#             */
/*   Updated: 2022/07/01 17:25:47 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

void	get_outfile(int *n, char *str, t_command *command_temp)
{
	char	*val;
	int		i;

	i = *n + 1;
	skipspace(&i, str);
	*n = i;
	skip_quots(str, &i);
	val = ft_substr(str, *n, i - (*n));
	get_redirections_token(command_temp);
	if (!*val)
		command_temp->rdc_tmp->tkn = NULL;
	else
	{
		val = dollar_handler(val);
		val = quots_handler(val);
		command_temp->rdc_tmp->tkn = ft_strdup(val);
	}
	command_temp->rdc_tmp->cmd = OUTFILE;
	free(val);
	*n = i - 1;
}

void	get_infile(int *n, char *str, t_command *command_temp)
{
	char	*val;
	int		i;

	i = *n + 1;
	skipspace(&i, str);
	*n = i;
	skip_quots(str, &i);
	get_redirections_token(command_temp);
	val = ft_substr(str, *n, i - (*n));
	if (!*val)
		command_temp->rdc_tmp->tkn = NULL;
	else
	{
		val = dollar_handler(val);
		val = quots_handler(val);
		command_temp->rdc_tmp->tkn = ft_strdup(val);
	}
	free(val);
	command_temp->rdc_tmp->cmd = INFILE;
	*n = i - 1;
}

void	get_herdoclimiter(int *n, char *str, t_command *command_temp)
{
	char	*val;
	int		i;

	i = *n + 2;
	skipspace(&i, str);
	*n = i;
	skip_quots(str, &i);
	get_redirections_token(command_temp);
	val = ft_substr(str, *n, i - (*n));
	if (!*val)
		command_temp->rdc_tmp->tkn = NULL;
	else
	{
		g_util->herdoc_expand = check_quots(val);
		val = quots_handler(val);
		command_temp->rdc_tmp->tkn = ft_strdup(val);
	}
	free(val);
	command_temp->rdc_tmp->cmd = HERDOC;
	*n = i - 1;
}

void	get_appendfile(int *n, char *str, t_command *command_temp)
{
	char	*val;
	int		i;

	i = *n + 2;
	skipspace(&i, str);
	*n = i;
	skip_quots(str, &i);
	val = ft_substr(str, *n, i - (*n));
	get_redirections_token(command_temp);
	if (!*val)
		command_temp->rdc_tmp->tkn = NULL;
	else
	{
		val = dollar_handler(val);
		val = quots_handler(val);
		command_temp->rdc_tmp->tkn = ft_strdup(val);
	}
	free(val);
	command_temp->rdc_tmp->cmd = APPEND;
	*n = i - 1;
}

void	skip_quots(char *str, int *n)
{
	int	i;
	int	quot;

	i = *n;
	quot = 0;
	while (str[i])
	{
		if (ft_isdilimiter(str[i]) && !quot)
			break ;
		if (!quot && (str[i] == '\'' || str[i] == '\"'))
			quot = str[i];
		else if (quot && str[i] == quot)
			quot = 0;
		i++;
	}
	*n = i;
}
