/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:47:02 by zboudair          #+#    #+#             */
/*   Updated: 2022/06/10 09:57:45 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int	ft_numlen(int n)
{
	int				i;
	unsigned int	nbr;

	i = 0;
	if (n < 0)
	{
		nbr = n * -1;
		i++;
	}
	else if (n == 0)
	{
		i = i + 1;
		nbr = n;
	}
	else
		nbr = n;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

static	char	*ft_convert(int n, int nlen, char *arr)
{
	int				i;
	unsigned int	nbr;
	int				nb;

	arr[nlen] = '\0';
	if (n > 0)
	{
		i = nlen - 1;
		nbr = n;
	}
	else
	{
		i = nlen - 1;
		arr[0] = '-';
		nbr = n * -1;
		nlen = nlen - 1;
	}
	while (nlen-- > 0)
	{
		nb = nbr % 10 + '0';
		nbr = nbr / 10;
		arr[i--] = nb;
	}
	return (arr);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*ret;

	i = ft_numlen(n);
	ret = (char *)malloc((i + 1) * sizeof(char));
	if (ret == 0)
		return (0);
	if (n == 0)
	{
		ret[0] = '0';
		ret[1] = '\0';
		return (ret);
	}
	ret = ft_convert(n, i, ret);
	return (ret);
}
