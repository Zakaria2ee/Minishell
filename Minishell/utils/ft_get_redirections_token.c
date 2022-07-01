/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_redirections_token.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:12:46 by zboudair          #+#    #+#             */
/*   Updated: 2022/06/06 13:57:47 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

void	get_redirections_token(t_command *commands)
{
	if (commands->rdc_token)
	{
		commands->rdc_tmp->next = ft_newtoken();
		commands->rdc_tmp = commands->rdc_tmp->next;
		commands->rdc_tmp->next = NULL;
	}
	else
	{
		commands->rdc_tmp = ft_newtoken();
		commands->rdc_token = commands->rdc_tmp;
		commands->rdc_tmp->next = NULL;
	}
}

void	get_arg_token(t_command *commands)
{
	if (commands->arg_token)
	{
		commands->arg_tmp->next = ft_newargtoken();
		commands->arg_tmp = commands->arg_tmp->next;
		commands->arg_tmp->next = NULL;
	}
	else
	{
		commands->arg_tmp = ft_newargtoken();
		commands->arg_token = commands->arg_tmp;
		commands->arg_tmp->next = NULL;
	}
}
