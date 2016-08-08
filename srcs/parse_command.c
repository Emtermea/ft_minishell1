/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtermea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 18:43:48 by emtermea          #+#    #+#             */
/*   Updated: 2016/08/07 18:43:50 by emtermea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static char *builtins[] = {
	"env",
	"setenv",
	"unsetenv",
	"cd",
	"exit",
	"echo",
	"pwd",
	NULL
};

static int	is_builtin(char const *line)
{
	int i;

	i = 0;
	while (builtins[i])
	{
		if (!ft_strcmp(line, builtins[i]))
			return (1);
		i++;
	}
	return (0);
}

static int is_binary(char const *line, t_env *env)
{
	(void)line;
	(void)env;

	return (0);
}

void parse_command(char const *line, t_env *env)
{
	char **command_tab;

	command_tab = ft_strsplit(line, ' ');
	if (is_builtin(command_tab[0]) == 1)
		exec_builtin(command_tab, env);
	else if (is_binary(command_tab[0], env) == 1)
		exec_binary(command_tab, env);
	else
		ft_putendl_fd(ERR_CMD, 2);
	ft_free_array(&command_tab);
}
