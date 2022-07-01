/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_file_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:21:15 by mabenchi          #+#    #+#             */
/*   Updated: 2022/06/30 12:16:44 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/error.h"

void	print_err_no_dir(char *cmd, char *path)
{
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": no such file or directory: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd("\n", 2);
}

void	print_err_unset(char *var, char *command)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(":", 2);
	ft_putstr_fd(" `", 2);
	ft_putstr_fd(var, 2);
	ft_putstr_fd("`: not a valid identifier\n", 2);
}

int	print_err_get_cmd(char *argv)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(argv, 2);
	ft_putstr_fd(": command not found\n", 2);
	g_util->status = 127;
	return (0);
}

void	print_err_ambiguous(char *temp)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(temp, 2);
	ft_putstr_fd(" : No such file or directory\n", 2);
}

void	print_err_syntax(char c)
{
	ft_putstr_fd("Minishell: syntax error near unexpected token `", 2);
	ft_putstr_fd(&c, 2);
	ft_putstr_fd("'\n", 2);
}
