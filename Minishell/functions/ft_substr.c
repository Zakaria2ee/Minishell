/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:19:31 by zboudair          #+#    #+#             */
/*   Updated: 2022/06/30 11:30:26 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char	*s, int start, int len)
{
	char	*sub;
	int		i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	else if (len > ft_strlen(s))
		return (NULL);
	sub = malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[i] != '\0')
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
