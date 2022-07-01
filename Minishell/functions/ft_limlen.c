/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_limlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:26:11 by mabenchi          #+#    #+#             */
/*   Updated: 2022/06/26 18:55:07 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	limlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (!ft_isdilimiter(str[i]))
		i++;
	return (i);
}
