/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtermea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 20:49:42 by emtermea          #+#    #+#             */
/*   Updated: 2016/08/10 20:49:44 by emtermea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

size_t			ft_strlen_tab(char **command)
{
	size_t		size;

	size = 0;
	while (command[size])
		size++;
	return (size);
}

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
