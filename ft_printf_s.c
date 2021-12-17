/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:48:02 by kshantay          #+#    #+#             */
/*   Updated: 2021/12/16 14:06:19 by kshantay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_c_s(va_list ap, char format, int *count)
{
	char	c;
	char	*str;

	if (format == 'c')
	{
		c = va_arg(ap, int);
		write(1, &c, 1);
		*count += 1;
	}
	else if (format == 's')
	{
		str = va_arg(ap, char *);
		if (str == NULL)
			*count += write(1, "(null)", 6);
		else
		{
			while (*str)
			{
				write(1, str, 1);
				*count += 1;
				str += 1;
			}
		}
	}
}
