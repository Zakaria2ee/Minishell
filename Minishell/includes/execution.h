/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:59:04 by mabenchi          #+#    #+#             */
/*   Updated: 2022/06/28 18:09:58 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H
# include "../includes/Minishell.h"
# include "../includes/libft.h"

typedef struct s_exe{
	int		ret;
	int		fdin;
	int		fdout;
	int		**pipe_fd;
	char	*path;
	int		size_lst;
	int		tmpin;
	int		tmpout;
}	t_exe;

char	*get_cmd_path(t_cmd *cmd, int i);
int		**pipes_create(int size);
void	close_all(int **pipe_fd, int size);
int		is_built_in(t_cmd *cmd);
void	execute_built_in(t_cmd *cmd, t_exe *exe, int to_dup);
t_env	*is_in_env(t_env *env, char **var_val, char *var, int to_free);

void	dup_fdin_fdout(int to_dup, t_exe *exe);
char	*split_to_path(void);
t_env	*find_pwd(char *var_name);
void	replace_var(char *var_name, char *path);
void	p(t_env *tmp, char *path);
void	change_pwd(int i);
void	cd_no_arg(char **path, int *to_free, char *var_name);

t_env	*is_in_env(t_env *env, char **var_val, char *var, int to_free);
char	**split_one_eq(char *var);
t_env	*norm(char	**var, int i, int *status, t_env **env);
int		add_var(t_env *var_node, int status, char *var, int join);
int		while_loop_export(char **var, t_env **env);
int		to_join(char *var);
void	fork_exe(t_cmd *cmd, t_exe *exe);
void	child_work(t_cmd *cmd, t_exe *exe);
int		zero_or_not(char *var);
#endif
