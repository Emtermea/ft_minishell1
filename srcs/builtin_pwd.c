/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtermea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 20:11:45 by emtermea          #+#    #+#             */
/*   Updated: 2016/08/08 20:11:46 by emtermea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int	builtin_pwd(char **command, t_env *env)
{
	printf("%s\n", __func__);

	size_t	size;
	char	*buf;

	(void)command;
	(void)env;
	size = 
	buf = (char *)malloc((size_t)size));
	getcwd(buf, size);
	return (1);
}
