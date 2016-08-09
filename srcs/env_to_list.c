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

void 	env_to_list(t_env **env, char **env_tab)
{
	char **tab;

	if (env_tab)
	{
		while (*env_tab)
		{
			tab = ft_strsplit(*env_tab, '=');
			list_add_next(env, create_link(tab));
			ft_free_array(&tab);
			env_tab++;
		}
	}
}
