/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtermea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 19:48:28 by emtermea          #+#    #+#             */
/*   Updated: 2016/04/08 19:48:29 by emtermea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

t_env	*create_link(char **env)
{
	t_env	*link;

	link = (t_env *)malloc(sizeof(t_env));
	if (link && env)
	{
		if (env && env[0])
		{
			 link->key = ft_strdup(env[0]);
			 if (env[1] == NULL)
			 	link->value = ft_strdup("");
			 else
			 	link->value = ft_strdup(env[1]);
			 link->next = NULL;
		}
		else
			ft_putendl_fd(ERR_SETENV, 2);
	}
	return (link);
}

t_env	*list_add_next(t_env *env, t_env *link)
{
	t_env *start;

	start = env;
	if (env)
	{
		while (env->next)
			env = env->next;
		env->next = link;
	}
	else
		start = link;
	return start;
}
