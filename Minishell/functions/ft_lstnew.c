/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:16:14 by zboudair          #+#    #+#             */
/*   Updated: 2022/06/10 09:57:40 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

t_command	*ft_lstnew(void)
{
	t_command	*head;

	head = malloc(sizeof(t_command));
	if (!head)
		return (0);
	head->next = NULL;
	return (head);
}
