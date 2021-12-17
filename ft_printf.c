/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:59:37 by kshantay          #+#    #+#             */
/*   Updated: 2021/12/16 15:51:39 by kshantay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static	void	ft_old(int *count)
{
	write(1, "%", 1);
	*count += 1;
}

static	void	ft_arg(va_list ap, char format, int *count)
{
	if (format == 's' || format == 'c')
		ft_printf_c_s(ap, format, count);
	else if (format == '%')
		ft_old(count);
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(ap, int), format, count);
	else if (format == 'x' || format == 'X' || format == 'u')
		ft_putnbr(va_arg(ap, unsigned int), format, count);
	else if (format == 'p')
		ft_putnbr(va_arg(ap, unsigned long long), format, count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			ft_arg(ap, *format, &count);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
