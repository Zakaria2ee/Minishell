/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:05:22 by zboudair          #+#    #+#             */
/*   Updated: 2022/07/01 17:18:47 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"
#include "../includes/libft.h"

void	signlas_handler(void)
{
	signal(SIGINT, signal_routine);
	signal(SIGQUIT, SIG_IGN);
}

void	signal_routine(int sig)
{
	if (sig == SIGINT)
	{
		if (g_util->herdoc == 0)
		{
			write(1, "\n", 2);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
		else if (g_util->herdoc == 1)
		{
			g_util->signal_status = 2;
			close(g_util->fd[0]);
			close(g_util->fd[1]);
			close(0);
		}	
	}
	g_util->status = 1;
}
