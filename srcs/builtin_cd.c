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

int	builtin_cd(char **command, t_env *env)
{
	printf("%s\n", __func__);
	(void)command;
	(void)env;
	return (1);
}
