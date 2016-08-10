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

static	size_t	ft_strlen_tab(char **command)
{
	size_t	size;

	size = 0;
	while (command[size])
		size++;
	return (size);
}

int 	builtin_set_env(char **command, t_env **env)
{
	printf("%s\n", __func__);
	t_env *tmp;

	tmp = *env;
    if (tmp)
    {
        if (command && command[0])
        {
			if (ft_strlen_tab(command) <= 3)
			{
				while (tmp)
            	{
                	if (!ft_strcmp(tmp->key, command[1]))
                	{
                  		ft_strdel(&tmp->key);
                    	tmp->key = ft_strdup(command[1]);
                    	if (!command[2])
                      	tmp->value = ft_strdup("");
                    	else
                      	tmp->value = ft_strdup(command[2]);
                    	return (0);
                	}
                	tmp = tmp->next;
            	}
				list_add_next(env, create_link(&command[1]));
			}
			else
				ft_putendl_fd(ERR_ARG, 2);
        }
    }
	return (1);
}
