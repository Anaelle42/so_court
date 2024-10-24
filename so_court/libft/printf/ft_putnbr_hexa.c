/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:19:43 by ahenault          #+#    #+#             */
/*   Updated: 2023/12/12 17:17:52 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hexa(unsigned int n, char format, int *size)
{
	char	*lowercase_alphabet;
	char	*uppercase_alphabet;

	lowercase_alphabet = "0123456789abcdef";
	uppercase_alphabet = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_putnbr_hexa((n / 16), format, size);
		ft_putnbr_hexa((n % 16), format, size);
	}
	else
	{
		if (format == 'x' || format == 'p')
			ft_putchar(lowercase_alphabet[n], 1);
		else if (format == 'X')
			ft_putchar(uppercase_alphabet[n], 1);
		(*size)++;
	}
}

void	ft_putnbr_ptr(unsigned long long n, int *size)
{
	char	*lowercase_alphabet;

	lowercase_alphabet = "0123456789abcdef";
	if (n >= 16)
	{
		ft_putnbr_ptr((n / 16), size);
		ft_putnbr_ptr((n % 16), size);
	}
	else
	{
		ft_putchar(lowercase_alphabet[n], 1);
		(*size)++;
	}
}

void	ft_printp(unsigned long long nb, int *size)
{
	if (!nb)
	{
		ft_putstr_fd("(nil)", 1);
		*size = *size + 5;
		return ;
	}
	write(1, "0x", 2);
	*size = *size + 2;
	ft_putnbr_ptr(nb, size);
}
