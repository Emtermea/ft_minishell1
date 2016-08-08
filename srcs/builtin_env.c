/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtermea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 20:11:19 by emtermea          #+#    #+#             */
/*   Updated: 2016/08/08 20:11:20 by emtermea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static void print_env(t_env *list)
{
	if (list)
	{
		while (list)
		{
			ft_putstr(list->key);
			ft_putchar('=');
			ft_putendl(list->value);
			list = list->next;
		}
	}
}

int builtin_env(char **command, t_env *env)
{
	(void)command;
	printf("%s\n", __func__);
	if (env != NULL)
	{
		print_env(env);
		return (0);
	}
	else
		return (1);
}
