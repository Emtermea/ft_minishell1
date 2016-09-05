/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtermea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 20:11:11 by emtermea          #+#    #+#             */
/*   Updated: 2016/08/08 20:11:12 by emtermea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

/*char	*ft_strclean(char const *str)
{
	char	clear[4096];
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (str)
	{
		ft_memset(clear, '\0', 4096);
		while (ft_isspace(*str))
			str++;
		if (!str || !*str)
			return (NULL);
		while (str[++i] && j < 4096)
		{
			if (!ft_isspace(str[i]))
				clear[j++] = str[i];
			else
			{
				if (str[i + 1] && !ft_isspace(str[i + 1]))
					clear[j++] = ' ';
			}
		}
	}
	return (ft_strdup(clear));
}*/

int	builtin_echo(char **command, t_env **env)
{
	printf("%s\n", __func__);
	(void)env;
	int	i;
	size_t	size;

	i = 1;
	if (command)
	{
		size = ft_strlen_tab(command);
		while (command[i])
		{
			ft_putstr(command[i]);
			i++;
			if (i < (int)size)
				ft_putchar(' ');
		}
		ft_putchar('\n');
		return (0);
	}
	return (1);
}
