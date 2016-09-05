/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtermea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 20:11:45 by emtermea          #+#    #+#             */
/*   Updated: 2016/08/08 20:11:46 by emtermea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int	builtin_pwd(char **command, t_env **env)
{
	char *pwd;
	(void)command;
	(void)env;
	if ((pwd = getcwd(NULL, 0)) != NULL)
	{
		ft_putendl(pwd);
		ft_strdel(&pwd);
		return (0);
	}
	return (1);
}
