/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newargtoken.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:50:36 by zboudair          #+#    #+#             */
/*   Updated: 2022/06/06 14:07:15 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

t_arg_token	*ft_newargtoken(void)
{
	t_arg_token	*head;

	head = malloc(sizeof(t_arg_token) * sizeof(t_arg_token));
	if (!head)
		return (0);
	head->next = NULL;
	return (head);
}
