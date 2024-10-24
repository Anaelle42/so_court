/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:07:03 by ahenault          #+#    #+#             */
/*   Updated: 2023/11/22 17:34:53 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (len < size)
		size = len;
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] && j < size)
	{
		res[j] = s[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}
