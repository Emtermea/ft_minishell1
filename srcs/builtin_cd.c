/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtermea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 20:11:01 by emtermea          #+#    #+#             */
/*   Updated: 2016/08/08 20:11:02 by emtermea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

/*static int	ft_check_access(char *path)
{
	if (path)
	{
		if (access(path, F_OK) == 0)
		{
			if (access(path, X_OK) == 0)
				return (0);
			else
				ft_putendl_fd(ERR_PERM, 2);
		}
		else
			ft_putendl_fd(ERR_EXIST, 2);
	}
	return (-1);
}*/


int	builtin_cd(char **command, t_env **env)
{
	printf("%s\n", __func__);
	// t_env	tmp;
	(void)env;
	int	ret;

	ret = 0;
	if (command && command[0])
	{
		if (ft_strlen_tab(command) <= 2)
		{
			ret = chdir(command[1]);
			char *pwd = getcwd(NULL, 0);
			char *tmp[] = {
				"setenv",
				"PWD",
				pwd,
				NULL
		};

			if (!ret)
			{
				builtin_set_env(tmp, env);
				return (0);
			}
		}
		else
			ft_putendl_fd(ERR_ARG, 2);
	}
	return (1);
}
