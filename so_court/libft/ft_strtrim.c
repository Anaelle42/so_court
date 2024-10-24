/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:57:33 by ahenault          #+#    #+#             */
/*   Updated: 2023/11/22 17:34:29 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		end;
	int		size;
	char	*str;

	i = 0;
	while (s1[i] && is_set(s1[i], set) == 1)
		i++;
	end = ft_strlen(s1);
	while (end > i && is_set(s1[end - 1], set) == 1)
		end--;
	size = end - i;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	ft_bzero(str, sizeof(char) * (size + 1));
	ft_strncpy(str, &s1[i], size);
	str[size] = '\0';
	return (str);
}
