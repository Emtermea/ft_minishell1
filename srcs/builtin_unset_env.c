/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtermea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 20:12:12 by emtermea          #+#    #+#             */
/*   Updated: 2016/08/08 20:12:13 by emtermea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int 	builtin_unset_env(char **command, t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	printf("%s\n", __func__);
	if (tmp)
	{
		if (!ft_strcmp(tmp->key, command[0]))
			tmp = tmp->next;
		while (tmp->next)
		{
			if (!ft_strcmp(tmp->next->key, command[0]))
			{
				tmp->next = tmp->next->next;
				return (0);
			}
			tmp = tmp->next;
		}
	}
	return (1);
}
