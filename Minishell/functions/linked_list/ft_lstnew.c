/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:09:33 by mabenchi          #+#    #+#             */
/*   Updated: 2022/06/10 09:59:38 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_env	*ft_lst_new(void *content)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->var = content;
	env->next = NULL;
	return (env);
}
