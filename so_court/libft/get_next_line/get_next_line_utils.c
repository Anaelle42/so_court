/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:03:44 by ahenault          #+#    #+#             */
/*   Updated: 2024/04/03 18:32:51 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strcpy(char *dst, const char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	char	*str;
	int		i;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = ft_strcpy(str, s1);
	ft_strcpy(&str[i], s2);
	free(s1);
	return (str);
}
