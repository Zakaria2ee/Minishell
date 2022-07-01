/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newtoken.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:51:53 by zboudair          #+#    #+#             */
/*   Updated: 2022/06/06 14:13:03 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

t_rdc_token	*ft_newtoken(void)
{
	t_rdc_token	*head;

	head = malloc(sizeof(t_rdc_token));
	if (!head)
		return (0);
	head->next = NULL;
	return (head);
}
