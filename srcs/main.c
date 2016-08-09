/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtermea <emtermea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 18:37:21 by emtermea          #+#    #+#             */
/*   Updated: 2016/08/07 18:39:28 by emtermea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include "ft_sh1.h"

int		main(int ac, char **av, char **envp)
{
	char	*line;
	t_env 	*env;

	(void)ac;
	(void)av;
	env = NULL;
	env_to_list(&env, envp);
	while ("Manue est trop geniale\n")
	{
		ft_print_color(BLUE, "PROMPT A DEUX BALLES$> ", 1);
		line = ft_strtrim(stdin_read());
		if (line)
		{
			parse_command(line, &env);
			ft_strdel(&line);
		}
	}
	return (0);
}
