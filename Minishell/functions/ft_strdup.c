/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:32:57 by zboudair          #+#    #+#             */
/*   Updated: 2022/06/30 11:29:53 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(char *str)
{
	int		i;
	int		len;
	char	*copy;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	copy = (char *)malloc(len * sizeof(char) + 1);
	if (copy == NULL)
	{
		return (0);
	}
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
