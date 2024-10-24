/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:08:31 by ahenault          #+#    #+#             */
/*   Updated: 2023/11/17 17:22:12 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dst[j] && j < size)
		j++;
	while (src[i] && size && i + j < size - 1)
	{
		dst[j + i] = src[i];
		i++;
	}
	if (j < size)
		dst[j + i] = '\0';
	while (src[i])
		i++;
	return (i + j);
}
