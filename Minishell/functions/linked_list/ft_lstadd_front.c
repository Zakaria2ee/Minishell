/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:15:14 by mabenchi          #+#    #+#             */
/*   Updated: 2022/06/10 09:59:57 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstadd_front(t_env **lst, t_env *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
