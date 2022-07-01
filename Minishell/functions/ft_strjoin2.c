/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:33:18 by zboudair          #+#    #+#             */
/*   Updated: 2022/06/12 20:36:28 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	int		size;
	int		i;
	int		j;
	char	*arr;

	i = 0;
	j = 0;
	if (!s2)
		return (s1);
	size = ft_strlen(s1) + ft_strlen(s2);
	arr = malloc((size + 1) * sizeof(char));
	if (arr == 0)
		return (0);
	if (s1)
	{
		while (s1[j] && i < size)
			arr[i++] = s1[j++];
	}
	j = 0;
	while (s2[j] && i < size)
		arr[i++] = s2[j++];
	arr[i] = '\0';
	freeing(s1, s2);
	return (arr);
}

void	freeing(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
}
