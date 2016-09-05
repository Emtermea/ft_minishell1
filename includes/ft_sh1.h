/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtermea <emtermea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 18:47:23 by emtermea          #+#    #+#             */
/*   Updated: 2015/03/25 12:41:45 by emtermea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

// ATTENTION
# include <stdio.h>

typedef struct  s_env
{
  char  *key;
  char  *value;
  struct  s_env *next;
}               t_env;

typedef struct	s_builtin
{
	char	*str;
	int		(*f)(char **command, t_env **env);
}				t_builtin;

# define ERR_CMD "command not found"
# define ERR_BUILTIN "error exec builtin"
# define ERR_SETENV "setenv fail"
# define ERR_ARG "setenv: Too many arguments."
# define ERR_PERM "Permission denied"
# define ERR_EXIST "No such file or directory."

/*
** PARSE / EXEC
*/
void parse_command(char const *line, t_env **env);
void exec_builtin(char **command, t_env **env);
void exec_binary(char **command, t_env *env);

/*
** BUILTINS
*/
int 		builtin_env(char **command, t_env **env);
int 		builtin_set_env(char **command, t_env **env);
int 		builtin_unset_env(char **command, t_env **env);
int 		builtin_echo(char **command, t_env **env);
int 		builtin_cd(char **command, t_env **env);
int 		builtin_pwd(char **command, t_env **env);
int 		builtin_exit(char **command, t_env **env);

/*
** LIST
*/
void	list_add_next(t_env **start, t_env *link);
t_env	*create_link(char **env);

/*
** ENV
*/
void 	env_to_list(t_env **env, char **env_tab);

/*
** MISC
*/
char	*stdin_read(void);
void	ft_free_array(char ***array);
size_t	ft_strlen_tab(char **tab);

#endif
