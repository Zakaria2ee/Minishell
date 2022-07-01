/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:46:52 by mabenchi          #+#    #+#             */
/*   Updated: 2022/06/10 09:59:54 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstclear(t_env **lst)
{
	t_env	*last;

	while (*lst)
	{
		last = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(last);
	}
	*lst = NULL;
}
