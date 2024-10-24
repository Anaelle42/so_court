/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:36:09 by ahenault          #+#    #+#             */
/*   Updated: 2023/11/30 17:13:26 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count(unsigned int n)
{
	int	nb;

	nb = 0;
	while (n > 0)
	{
		nb++;
		n = n / 10;
	}
	return (nb);
}

char	*ft_itoaunsigned(unsigned int n)
{
	char	*ptr;
	int		size;

	size = ft_count(n);
	ptr = malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	ptr[size] = '\0';
	while (n != 0)
	{
		ptr[size - 1] = n % 10 + '0';
		n = n / 10;
		size--;
	}
	return (ptr);
}

int	ft_printu(unsigned int n)
{
	int		len;
	char	*s;

	len = 0;
	if (n == 0)
		len = ft_putstr("0");
	else
	{
		s = ft_itoaunsigned(n);
		len = ft_putstr(s);
		free(s);
	}
	return (len);
}
