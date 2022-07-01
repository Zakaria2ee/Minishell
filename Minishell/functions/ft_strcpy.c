/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:18:06 by zboudair          #+#    #+#             */
/*   Updated: 2022/06/25 21:23:08 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcpy(char	*src, int *j)
{
	int		i;
	int		k;
	char	*ret;

	i = *j;
	k = 0;
	while (!ft_isdilimiter(src[i]) && !ft_isdilimiter2(src[i]) && src[i] != '$')
		i++;
	ret = malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (0);
	i = *j;
	while (!ft_isdilimiter(src[i]) && (ft_isalnum(src[i]) || src[i] == '_'))
	{
		ret[k] = src[i];
		i++;
		k++;
	}
	*j = i;
	ret[k] = '\0';
	return (ret);
}
