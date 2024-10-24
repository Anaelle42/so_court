/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:10:57 by ahenault          #+#    #+#             */
/*   Updated: 2024/04/03 18:21:48 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putnbr_hexa(unsigned int n, char format, int *size);
int		ft_printu(unsigned int n);
int		ft_printnbr(int nb);
int		ft_putstr(char *str);
int		ft_putchar(char c, int fd);
void	ft_putnbr_ptr(unsigned long long n, int *size);
void	ft_printp(unsigned long long nb, int *size);

#endif