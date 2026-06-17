/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbrs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 09:02:24 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/17 10:45:03 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nbr(t_fmt *f, char *prefix, char *digits)
{
	int	padding_zeros;
	int	spaces;

	padding_zeros = f->prec - ft_strlen(digits);
	if (padding_zeros < 0)
		padding_zeros = 0;
	spaces = f->width - ft_strlen(prefix) - padding_zeros - ft_strlen(digits);
	if (!f->minus && !(f->zero && f->prec < 0))
		ft_putpading(f, ' ', spaces);
	ft_putstr_pf(f, prefix);
	if (!f->minus && f->zero && f->prec < 0)
		ft_putpading(f, '0', spaces);
	ft_putpading(f, '0', padding_zeros);
	ft_putstr_pf(f, digits);
	if (f->minus)
		ft_putpading(f, ' ', spaces);
}

void	ft_print_base(t_fmt *f, unsigned long nb, char *base, char *prefix)
{
	char	buf[21];
	char	*digits;

	if (nb == 0 && f->prec == 0)
		digits = "";
	else
		digits = ft_utoa_base(nb, base, buf);
	ft_print_nbr(f, prefix, digits);
}

void	ft_print_int(t_fmt *f)
{
	long			n;
	unsigned long	modulo;
	char			*prefix;

	n = (long)va_arg(f->args, int);
	prefix = "";
	if (n < 0)
		prefix = "-";
	else if (f->plus)
		prefix = "+";
	else if (f->space)
		prefix = " ";
	if (n < 0)
		modulo = (unsigned long)(-n);
	else
		modulo = (unsigned long)n;
	ft_print_base(f, modulo, "0123456789", prefix);
}

void	ft_print_hex(t_fmt *f, int uppercase)
{
	unsigned int	n;
	char			*prefix;
	char			*base;

	base = "0123456789abcdef";
	if (uppercase)
		base = "0123456789ABCDEF";
	n = va_arg(f->args, unsigned int);
	prefix = "";
	if (f->hash && n)
	{
		prefix = "0x";
		if (uppercase)
			prefix = "0X";
	}
	ft_print_base(f, n, base, prefix);
}
