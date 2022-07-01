/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newcommand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:31:41 by zboudair          #+#    #+#             */
/*   Updated: 2022/06/10 10:17:00 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

t_command	*ft_newcommand(t_command *command_temp, t_command **commands)
{
	if (*commands)
	{
		command_temp->next = ft_lstnew();
		command_temp = command_temp->next;
		command_temp->next = NULL;
	}
	else
	{
		command_temp = ft_lstnew();
		*commands = command_temp;
		command_temp->next = NULL;
	}
	command_temp->rdc_token = NULL;
	command_temp->arg_token = NULL;
	return (command_temp);
}
