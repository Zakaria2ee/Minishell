/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:00:49 by mabenchi          #+#    #+#             */
/*   Updated: 2022/06/10 09:59:41 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_env	*ft_lstmap(t_env *lst, void *(*f)(void *))
{
	t_env	*newlst;
	t_env	*lstitr;

	if (!lst)
		return (NULL);
	newlst = ft_lst_new(f(lst->var));
	if (!newlst)
		return (NULL);
	lstitr = newlst;
	lst = lst->next;
	while (lst)
	{
		lstitr->next = ft_lst_new(f(lst->var));
		if (!lstitr->next)
		{
			ft_lstclear(&newlst);
			return (NULL);
		}
		lstitr = lstitr->next;
		lst = lst->next;
	}
	return (newlst);
}
