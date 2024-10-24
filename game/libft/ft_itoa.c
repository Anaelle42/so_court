/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:49:11 by ahenault          #+#    #+#             */
/*   Updated: 2023/11/22 17:20:01 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long n)
{
	int	nb;

	nb = 0;
	if (n < 0)
	{
		n = -n;
		nb++;
	}
	while (n > 0)
	{
		nb++;
		n = n / 10;
	}
	return (nb);
}

static char	*ft_mallocitoa(long n)
{
	char	*ptr;
	int		size;
	int		i;

	i = 0;
	size = ft_count(n);
	ptr = malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	if (n < 0)
	{
		ptr[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		ptr[size - 1 - i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	ptr[size] = '\0';
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	nb;

	nb = n;
	if (n == 0)
	{
		res = malloc(2 * sizeof(char));
		if (!res)
			return (NULL);
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	res = ft_mallocitoa(nb);
	return (res);
}
