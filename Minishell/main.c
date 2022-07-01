/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:32:09 by zboudair          #+#    #+#             */
/*   Updated: 2022/07/01 17:30:19 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Minishell.h"
#include "includes/execution.h"

t_env	*copy_env(char **envp)
{
	int		i;
	t_env	*env;

	i = 1;
	env = ft_lst_new(envp[0]);
	if (!env)
		exit(102);
	while (envp[i])
	{
		ft_lstadd_back(&env, ft_lst_new(ft_strdup(envp[i])));
		i++;
	}
	return (env);
}

static void	util_init(char **arg, char **env)
{
	g_util = malloc(sizeof(t_utils));
	g_util->args = arg;
	g_util->env = env;
	g_util->env_lst = copy_env(env);
	g_util->status = 0;
	g_util->signal_status = 0;
	g_util->herdoc = 0;
	g_util->dup_line = dup(0);
	g_util->cond = 0;
	g_util->herdoc_expand = 0;
}

static void	parse_execute(char *s, t_command *commands, t_cmd *cmd)
{
	(void)cmd;
	commands = lexing(s);
	if (commands->arg_token || commands->rdc_token)
	{
		cmd = parsing(commands);
		if (cmd)
		{
			execution(cmd);
			destroy2(cmd);
		}
	}
	destroy(commands);
}

int	main(int ac, char **arg, char **env)
{
	char		*s;
	t_command	*commands;
	t_cmd		*cmd;

	s = NULL;
	commands = NULL;
	cmd = NULL;
	util_init(arg, env);
	signlas_handler();
	while (ac)
	{
		s = readline("\033[0;32m~ minishell\x1b[0m ");
		if (!s)
		{
			printf("exit\n");
			exit(g_util->status);
		}
		if (*s != '\0')
			add_history(s);
		if (s && *s != '\0' && test_q(s))
			parse_execute(s, commands, cmd);
		free(s);
	}
}
