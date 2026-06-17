/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:59:57 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/17 16:28:50 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_flags(t_fmt *f)
{
	f->minus = 0;
	f->zero = 0;
	f->hash = 0;
	f->plus = 0;
	f->space = 0;
	f->width = 0;
	f->prec = -100;
}

int	ft_parse_flags(t_fmt *f, const char *fmt, int i)
{
	while (fmt[i] == '-' || fmt[i] == '0' || fmt[i] == ' ' || fmt[i] == '+'
		|| fmt[i] == '#')
	{
		if (fmt[i] == '-')
			f->minus = 1;
		else if (fmt[i] == '0')
			f->zero = 1;
		else if (fmt[i] == ' ')
			f->space = 1;
		else if (fmt[i] == '+')
			f->plus = 1;
		else if (fmt[i] == '#')
			f->hash = 1;
		i++;
	}
	return (i);
}

int	ft_parse_width_and_prec(t_fmt *f, const char *fmt, int i)
{
	while (fmt[i] >= '0' && fmt[i] <= '9')
	{
		f->width = f->width * 10 + (fmt[i] - '0');
		i++;
	}
	if (fmt[i] == '.')
	{
		i++;
		f->prec = 0;
		while (fmt[i] >= '0' && fmt[i] <= '9')
		{
			f->prec = f->prec * 10 + (fmt[i] - '0');
			i++;
		}
	}
	return (i);
}

int	ft_printf(const char *fmt, ...)
{
	t_fmt	f;
	int		i;

	if (!fmt)
		return (-1);
	f.count = 0;
	va_start(f.args, fmt);
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1])
		{
			ft_reset_flags(&f);
			i = ft_parse_flags(&f, fmt, i + 1);
			i = ft_parse_width_and_prec(&f, fmt, i);
			ft_route(&f, fmt[i++]);
		}
		else
			ft_putchar_pf(&f, fmt[i++]);
	}
	va_end(f.args);
	return (f.count);
}
