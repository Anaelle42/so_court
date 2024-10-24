/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:34:21 by ahenault          #+#    #+#             */
/*   Updated: 2023/11/21 16:03:54 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*ptr_dest;
	const char		*ptr_src;
	unsigned int	i;

	i = 0;
	ptr_dest = dest;
	ptr_src = src;
	if (ptr_dest < ptr_src)
	{
		while (i < n)
		{
			ptr_dest[i] = ptr_src[i];
			i++;
		}
	}
	if (ptr_dest > ptr_src)
	{
		i = n;
		while (i > 0)
		{
			ptr_dest[i - 1] = ptr_src[i - 1];
			i--;
		}
	}
	return (dest);
}
