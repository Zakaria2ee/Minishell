/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:51:57 by zboudair          #+#    #+#             */
/*   Updated: 2022/06/06 13:53:41 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

t_cmd	*ft_newcmd(void)
{
	t_cmd	*head;

	head = malloc(sizeof(t_cmd));
	if (!head)
		return (0);
	head->next = NULL;
	return (head);
}
