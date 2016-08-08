/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtermea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 19:59:02 by emtermea          #+#    #+#             */
/*   Updated: 2016/08/08 19:59:15 by emtermea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static t_builtin builtins[] = {
	{"env", builtin_env},
	{"setenv", builtin_set_env},
	{"unsetenv", builtin_unset_env},
	{"cd", builtin_cd},
	{"exit", builtin_exit},
	{"echo", builtin_echo},
	{"pwd", builtin_pwd},
	{NULL, NULL}
};

void exec_builtin(char **command, t_env *env)
{
	int i;

	i = 0;
	while (builtins[i].str)
	{
		if (ft_strcmp(builtins[i].str, command[0]) == 0)
		{
			builtins[i].f(command, env);
			return ;
		}
		i++;
	}
	ft_putendl_fd(ERR_BUILTIN, 2);
}

void exec_binary(char **command, t_env *env)
{
	(void)command;
	(void)env;
}
