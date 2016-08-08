/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_set_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtermea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 19:46:52 by emtermea          #+#    #+#             */
/*   Updated: 2016/04/08 19:46:54 by emtermea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int 	builtin_set_env(char **command, t_env *env)
{
	printf("%s\n", __func__);
	t_env *tmp;

	tmp = env;
    if (env)
    {
        if (command && command[0])
        {
            while (env)
            {
                if (!ft_strcmp(env->key, command[0]))
                {
                  	ft_strdel(&env->key);
                    env->key = ft_strdup(command[0]);
                    if (!command[1])
                      env->value = ft_strdup("");
                    else
                      env->value = ft_strdup(command[1]);
                    return (0);
                }
                env = env->next;
            }
            list_add_next(env, create_link(&command[1]));
        }
    }

	return (0);
}
