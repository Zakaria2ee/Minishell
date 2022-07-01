/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:01:40 by zboudair          #+#    #+#             */
/*   Updated: 2022/07/01 17:31:56 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define OUTFILE 1
# define INFILE 2
# define APPEND 3
# define HERDOC 4
# define ARG 5

# include "libft.h"
# include "error.h"

typedef struct arg_token_t
{
	int					cmd;
	char				*tkn;
	struct arg_token_t	*next;
}	t_arg_token;

typedef struct rdc_token_t
{
	int					cmd;
	char				*tkn;
	struct rdc_token_t	*next;
}	t_rdc_token;

typedef struct command_t
{
	t_arg_token			*arg_token;
	t_arg_token			*arg_tmp;
	t_rdc_token			*rdc_token;
	t_rdc_token			*rdc_tmp;
	struct command_t	*next;
}	t_command;

typedef struct cmd_t
{
	char			**argv;
	int				in_fd;
	int				out_fdl;
	int				id;
	int				rdc_check;
	struct cmd_t	*next;
}	t_cmd;

t_command	*lexing(char *s);
void		execution(t_cmd *cmd);
char		*expand(t_env	*env_lst, char *var);
t_command	*ft_newcommand(t_command *command_temp, t_command **commands);
void		get_command(char *str, t_command *command_temp);
t_rdc_token	*ft_newtoken(void);
t_command	*ft_lstnew(void);
t_cmd		*ft_newcmd(void);
t_arg_token	*ft_newargtoken(void);
void		get_arg_token(t_command *commands);
void		destroy(t_command *command_temp);
int			herdoc_handler(t_command *command, t_cmd *cmd);
t_cmd		*parsing(t_command *command);
void		ft_files_handler(t_command *command, t_cmd *cmd);
void		arguments_handler(t_command *command, t_cmd *cmd);
t_cmd		*ft_locate(t_command *command_temp);
void		signlas_handler(void);
char		*line_to_no_space(char *line);
int			test_q(char *line);
void		skip_token(char *str, int *j, int *quot);
int			arg_len(t_command *command_temp);
void		check_singlequot(char *str, int *i, int *single_quot);
void		check_dollar(char *str, int *i, int *single_quot, int *start);
int			ft_check1(t_command *temp, t_cmd *cmd, int*file);
void		ft_check(t_command *temp, t_cmd *cmd, int *file, int *fd);
void		signal_routine(int sig);
int			ft_lstsize(t_cmd *lst);
void		skip_quots(char *str, int *n);
char		*quots_handler(char *val);
char		*dollar_handler(char *str);
char		*get_dollarvalue(int *i, char *str);
void		get_arguments(t_command *command_temp, char *str);
void		replace1(char *str, char c1, char c2);
void		replace(char *str, char c1, char c2);
int			check_quots(char *str);
int			ft_check3(t_command *temp, t_cmd *cmd);
int			files_herdoc(int d, t_cmd *cmd, t_command *command);

void		get_redirections_token(t_command *commands);
void		get_redirections(t_command *command_temp, char *str);
void		get_outfile(int *n, char *str, t_command *command_temp);
void		get_infile(int *n, char *str, t_command *command_temp);
void		get_herdoclimiter(int *n, char *str, t_command *command_temp);
void		get_appendfile(int *n, char *str, t_command *command_temp);
void		destroy2(t_cmd *cmd);
int			ft_check2(t_command *temp, t_cmd *cmd, int*fd);
int			ft_freeing(char *str);
void		get_arg(int *n, char *str, t_command *command_temp, int type);
int			check_rdc(int *n, int *type, char *str);
int			check_fileserrors(t_command *command);
void		replace2(char *str, char a, char b);

//built_in

void		ft_exit(char **args);
void		ft_cd(char *path);
void		ft_pwd(void);
void		ft_echo(char **arg);
void		ft_env(t_env *env, char **arg);
void		ft_export(char **var, t_env **env);
void		ft_unset(char **var, t_env **env, int i);

//test_q
int			quotes(char *line, char **err);
int			pipes(char *no_space, char **err);
int			quotes(char *line, char **err);
int			varcmp(char *s1, char *s2);

int			test(char *var, char *command);

void		signal_routine(int sig);
#endif
