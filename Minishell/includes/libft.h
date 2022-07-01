/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 09:46:26 by zboudair          #+#    #+#             */
/*   Updated: 2022/06/30 15:15:45 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h> 
# include <sys/wait.h>
# include <signal.h>

//status=-1 var with no value
//status=0 var with "" value
//status=1 var with a value

typedef struct s_env
{
	char			*var;
	int				from_export;
	int				status;
	struct s_env	*next;
}	t_env;

typedef struct utils_t
{
	t_env	*env_lst;
	int		dup_line;
	int		cond;
	int		rdc_check;
	int		fd[2];
	char	**env;
	char	**args;
	int		status;
	int		signal_status;
	int		herdoc;
	int		herdoc_expand;
	char	*var;
	char	redir_err;
	int		h_doc_redir_err;
	char	*ambiguous_redir;
	int		oldpwd_is_set;
	int		firstunset;
}	t_utils;

t_utils		*g_util;
void		freeing(char *s1, char *s2);
void		skipspace(int *n, char *s);
int			ft_memcmp(char *s1, char *s2, int j);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isdilimiter(int c);
char		*ft_strjoin(char *s1, char *s2);
char		**ft_split(char	*s, char c);
char		*ft_substr(char *s, int start, int len);
char		*ft_strcpy(char	*src, int *j);
int			ft_strlen(const char	*str);
char		*ft_strdup(char *str);
int			ft_strcmp(char	*s1, char	*s2);
char		*ft_itoa(int n);
char		*ft_strchr(const char *s, int c);
void		ft_lstadd_back(t_env **lst, t_env *new);
void		ft_lstadd_front(t_env **lst, t_env *new);
void		ft_lstclear(t_env **lst);
void		ft_lstdelone(t_env *lst);
void		ft_lstiter(t_env *lst, void (*f)(void *));
t_env		*ft_lstlast(t_env *lst);
t_env		*ft_lstmap(t_env *lst, void *(*f)(void *));
t_env		*ft_lst_new(void *content);
int			ft_lst_size(t_env *lst);
char		*ft_strjoin2(char *s1, char *s2);
int			limlen(char *str);
int			ft_isdilimiter2(int c);
void		ft_putstr_fd(char *s, int fd);
int			ft_atoi(const char	*str);
void		rl_replace_line(char *str, int d);
char		*ft_strtrim(char *s, char const *set);
void		redir_in_quote(char *line);
int			two_redir(char **err, int *herdoc, int i, char cond);
int			redir_while_loop(char *var, char **err, int *herdoc, int space);
#endif
