/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtermea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 20:11:31 by emtermea          #+#    #+#             */
/*   Updated: 2016/08/08 20:11:33 by emtermea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int	builtin_exit(char **command, t_env **env)
{
	(void)command;
	(void)env;
	if (command)
	{
		exit(0);
		return (0);
	}
	return (1);
}
