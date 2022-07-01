/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:22:31 by mabenchi          #+#    #+#             */
/*   Updated: 2022/06/29 15:13:53 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include "Minishell.h"

void	print_err_no_dir(char *cmd, char *path);
void	print_err_unset(char *var, char *command);
int		print_err_get_cmd(char *argv);
void	print_err_ambiguous(char *temp);
void	print_err_syntax(char c);
#endif