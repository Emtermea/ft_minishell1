/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtermea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 19:48:20 by emtermea          #+#    #+#             */
/*   Updated: 2016/04/08 19:48:21 by emtermea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	ft_free_array(char ***array)
{
	char **tmp;

	tmp = *array;
	if (tmp)
	{
		while (*tmp)
		{
			free(*tmp);
			tmp++;
		}
		free(*array);
	}
	*array = NULL;
}

t_env	*env_to_list(char **env)
{
	t_env *start;
	char **tab;

	start = NULL;
	if (env)
	{
		while (*env)
		{
			tab = ft_strsplit(*env, '=');
			start = list_add_next(start, create_link(tab));
			ft_free_array(&tab);
			env++;
		}
	}
	return (start);
}
