/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtermea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 19:48:42 by emtermea          #+#    #+#             */
/*   Updated: 2016/04/08 19:48:43 by emtermea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"
# define BUF_SIZE 1024


char	*stdin_read(void)
{
	char	buf[BUF_SIZE];
	int		r;

	r = read(STDIN_FILENO, buf, BUF_SIZE - 1);
	if (r > 1)
	{
		buf[r - 1] = '\0'; /* r - 1 parce que on vire le \n */
		return (ft_strdup(buf)); /* retourne plutot la string nettoye et malloquee */
	}
	else if (r == 1)
		return (NULL);
	else if (r == 0) /* CTRL + D <==> End Of File */
		write(1, "exit\n", 5);
	else if (r == -1) /* Erreur READ() */
		write(2, "err read()\n", 11);
	else if (r == BUF_SIZE - 1) /* commande trop longue */
		write(2, "Command too long\n", 17);
	exit(-1);
	return (NULL);
}
