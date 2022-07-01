/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:27:16 by mabenchi          #+#    #+#             */
/*   Updated: 2022/06/29 15:31:27 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_search(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_bg(const char *s, const char *set)
{
	int	i;
	int	bg;

	i = 0;
	bg = 0;
	while (s[i])
	{
		if (!ft_search(set, s[i]))
		{
			bg = i;
			break ;
		}
		i++;
	}
	return (bg);
}

static int	ft_end(const char *s, const char *set)
{
	int	i;
	int	end;

	i = ft_strlen(s) - 1;
	end = 0;
	while (i >= 0)
	{
		if (!ft_search(set, s[i]))
		{
			end = i;
			break ;
		}
		i--;
	}
	return (end);
}

static char	*fill(char *trim, char *s, int bg, int end)
{
	int	i;

	i = 0;
	if (bg != 0 || end != 0)
	{
		trim = malloc(end - bg + 2);
		if (!trim)
			return (NULL);
		i = bg;
		while (i <= end)
		{
			trim[i - bg] = s[i];
			i++;
		}
	}
	else
		return (s);
	trim[i - bg] = '\0';
	free(s);
	return (trim);
}

char	*ft_strtrim(char *s, char const *set)
{
	int		i;
	int		bg;
	int		end;
	char	*trim;

	i = 0;
	bg = 0;
	end = 0;
	trim = NULL;
	bg = ft_bg(s, set);
	end = ft_end(s, set);
	return (fill(trim, s, bg, end));
}
