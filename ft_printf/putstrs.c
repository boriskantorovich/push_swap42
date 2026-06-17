/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstrs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:36:51 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/17 17:36:53 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putpad_str(t_fmt *f, char *s, int len)
{
	int	spaces;

	spaces = f->width - len;
	if (!f->minus)
		ft_putpading(f, ' ', spaces);
	while (len-- > 0)
		ft_putchar_pf(f, *s++);
	if (f->minus)
		ft_putpading(f, ' ', spaces);
}

void	ft_putone(t_fmt *f, char c)
{
	ft_putpad_str(f, &c, 1);
}

void	ft_print_str(t_fmt *f, char *s)
{
	int	len;

	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (f->prec >= 0 && f->prec < len)
		len = f->prec;
	ft_putpad_str(f, s, len);
}

void	ft_print_ptr(t_fmt *f, unsigned long p)
{
	if (p == 0)
		ft_putpad_str(f, "(nil)", 5);
	else
		ft_print_base(f, p, "0123456789abcdef", "0x");
}
