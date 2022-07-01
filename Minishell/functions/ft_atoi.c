/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:10:04 by mabenchi          #+#    #+#             */
/*   Updated: 2022/06/24 20:04:34 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#define LNG_MAX 9223372036854775807 

int	ft_atoi(const char	*str)
{
	int				i;
	unsigned long	res;
	int				sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		res = (res * 10) + (str[i++] - '0');
		if (res > LNG_MAX)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
	}
	return ((int)res * sign);
}
