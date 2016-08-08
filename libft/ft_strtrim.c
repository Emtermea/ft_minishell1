/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtermea <emtermea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 13:30:45 by emtermea          #+#    #+#             */
/*   Updated: 2014/11/15 19:27:28 by emtermea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

// char	*ft_strtrim(char const *s)
// {
// 	int		a;
// 	int		i;
// 	int		j;
// 	char	*str;

// 	a = 0;
// 	i = 0;
// 	str = NULL;
// 	if (s)
// 	{
// 		j = ft_strlen(s) - 1;
// 		while (s[i] && (s[i] < 33 || s[i] >= 126))
// 			i++;
// 		while (s[j] && (s[j] < 33 || s[j] >= 126))
// 			j--;
// 		str = (char*)malloc(sizeof((j - i) + 1));
// 		if (!str)
// 			return (NULL);
// 		while (i <= j)
// 			str[a++] = s[i++];
// 		str[a] = '\0';
// 	}
// 	return (str);
// }

char	*ft_strtrim(char const *s)
{
		char	*str;
		size_t	i;
		size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	str = ft_strsub(s, i, (j - i + 1));
	return (str);
} 
