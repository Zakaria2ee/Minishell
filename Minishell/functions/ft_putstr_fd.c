/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:26:48 by mabenchi          #+#    #+#             */
/*   Updated: 2022/06/23 20:01:44 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	len;

	if (s && fd >= 0)
	{
		len = ft_strlen(s);
		write(fd, s, len);
	}
}
