/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:20:46 by ahenault          #+#    #+#             */
/*   Updated: 2024/03/13 17:49:00 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_typecheck(const char format, va_list ap)
{
	int	len;
	int	*size;

	len = 0;
	size = &len;
	if (format == 'c')
		len += ft_putchar(va_arg(ap, int), 1);
	else if (format == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (format == 'i' || format == 'd')
		len += ft_printnbr(va_arg(ap, int));
	else if (format == 'u')
		len += ft_printu(va_arg(ap, unsigned int));
	else if (format == 'p')
		ft_printp(va_arg(ap, unsigned long long), size);
	else if (format == 'x' || format == 'X')
		ft_putnbr_hexa(va_arg(ap, unsigned int), format, size);
	else if (format == '%')
		len += ft_putchar('%', 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	unsigned int	len;
	int				i;

	len = 0;
	i = 0;
	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += ft_typecheck(format[i], ap);
		}
		else
		{
			ft_putchar(format[i], 1);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}
