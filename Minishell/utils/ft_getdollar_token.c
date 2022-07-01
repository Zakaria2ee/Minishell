/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdollar_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:32:31 by zboudair          #+#    #+#             */
/*   Updated: 2022/07/01 17:18:13 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

char	*dollar_handler(char *str)
{
	int		i;
	int		start;
	int		quots;

	i = 0;
	quots = 0;
	start = 0;
	g_util->var = NULL;
	replace1(str, '$', -2); 
	while (str[i] != '\0')
	{
		check_singlequot(str, &i, &quots);
		if (!i && str[i] == '$' && (str[i + 1] == '"' || str[i + 1] == '\''))
			start = i + 1;
		check_dollar(str, &i, &quots, &start);
		i++;
	}
	replace1(g_util->var, -2, '$');
	free(str);
	return (g_util->var);
}

void	check_dollar(char *str, int *i, int *quots, int *start)
{
	if (*i && str[*i] == '$' && *quots != '\'')
	{
		g_util->var = ft_strjoin2(g_util->var,
				ft_substr(str, *start, *i - *start));
		if (str[*i + 1] == '"')
			*start = *i + 1;
		else
			*start = *i;
	}
	if (str[*i] == '$' && *quots != '\''
		&& (ft_isalnum(str[*i + 1]) || str[*i + 1] == '_'))
	{
		g_util->var = ft_strjoin2(g_util->var, get_dollarvalue(i, str));
		*start = *i + 1;
	}
	if (str[*i] == '$' && *quots != '\'' && str[*i + 1] == '?')
	{
		g_util->var = ft_strjoin2(g_util->var, ft_itoa(g_util->status));
		*i += 1;
		*start = *i + 1;
	}
	if (str[*i + 1] == '\0')
		g_util->var = ft_strjoin2(g_util->var,
				ft_substr(str, *start, (*i + 1) - *start));
}

char	*get_dollarvalue(int *i, char *str)
{
	char	*var;
	int		j;

	j = *i + 1;
	var = NULL;
	if (ft_isalpha(str[j]) == 1)
		var = expand(g_util->env_lst, ft_strcpy(str, &j));
	else if (str[j] == '0')
	{
		j++;
		var = ft_strdup(g_util->args[0]);
	}
	else if (str[j] > '0' && str[j] <= '9')
	{
		var = NULL;
		j++;
	}
	else
		return (NULL);
	*i = j - 1;
	return (var);
}

void	check_singlequot(char *str, int *i, int *quots)
{
	if (!*quots && (str[*i] == 39 || str[*i] == '"'))
		*quots = str[*i];
	else if (*quots && (str[*i] == *quots))
		*quots = 0;
}

void	replace1(char *str, char a, char b)
{
	int	i;
	int	quots;

	if (!str)
		return ;
	i = 0;
	quots = 0;
	while (str[i])
	{
		if (!quots && (str[i] == 39 || str[i] == '"'))
			quots = str[i];
		else if (quots && (str[i] == quots))
			quots = 0;
		if (i && str[i] == a && str[i + 1] == '"' && quots)
			str[i] = b;
		i++;
	}
}

void	replace2(char *str, char a, char b)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] == a)
			str[i] = b;
		i++;
	}
}
