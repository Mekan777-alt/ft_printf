/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:46:24 by kshantay          #+#    #+#             */
/*   Updated: 2021/12/16 17:31:16 by kshantay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(const char c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

static	void	ft_itoa_x(unsigned long long num, char format, int *count)
{
	if (num > 15)
	{
		ft_itoa_x(num / 16, format, count);
		ft_itoa_x(num % 16, format, count);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0', count);
		else
		{
			if (format == 'x')
				ft_putchar(num - 10 + 'a', count);
			else
				ft_putchar(num - 10 + 'A', count);
		}
	}
}

static	void	ft_recurs_d(long long num, int *count)
{
	long long	new_w;

	if (num > 0)
	{
		ft_recurs_d(num / 10, count);
		new_w = num % 10 + 48;
		write(1, &new_w, 1);
		*count += 1;
	}
}

static	void	ft_itoa_p(unsigned long long num, int *count)
{
	if (num > 15)
	{
		ft_itoa_p(num / 16, count);
		ft_itoa_p(num % 16, count);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0', count);
		else
			ft_putchar(num - 10 + 'a', count);
	}
}

void	ft_putnbr(long long num, char format, int *count)
{
	if (format == 'd' || format == 'u' || format == 'i')
	{
		if (num == 0)
			*count += write(1, "0", 1);
		else if (num < 0)
		{
			*count += write(1, "-", 1);
			num *= -1;
			ft_recurs_d(num, count);
		}
		else if (num > 0)
			ft_recurs_d(num, count);
	}
	else if (format == 'x' || format == 'X' || format == 'p')
	{
		if (format == 'p')
		{
			num = (unsigned long long)num;
			*count += write(1, "0x", 2);
			ft_itoa_p(num, count);
		}
		else
			ft_itoa_x(num, format, count);
	}
}
