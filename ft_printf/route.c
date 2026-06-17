/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:29:36 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/17 16:29:40 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_route(t_fmt *f, char c)
{
	if (c == 'c')
		ft_putone(f, va_arg(f->args, int));
	else if (c == 's')
		ft_print_str(f, va_arg(f->args, char *));
	else if (c == 'p')
		ft_print_ptr(f, (unsigned long)va_arg(f->args, void *));
	else if (c == 'd' || c == 'i')
		ft_print_int(f);
	else if (c == 'u')
		ft_print_base(f, va_arg(f->args, unsigned int), "0123456789", "");
	else if (c == 'x')
		ft_print_hex(f, 0);
	else if (c == 'X')
		ft_print_hex(f, 1);
	else if (c == '%')
		ft_putone(f, '%');
	else
		ft_putpad_str(f, &c, 1);
}
