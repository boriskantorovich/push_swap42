/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:34:37 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/17 18:17:32 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_pf(t_fmt *f, char c)
{
	if (write(2, &c, 1) == 1)
		f->count++;
}

void	ft_putstr_pf(t_fmt *f, char *s)
{
	int	i;

	i = 0;
	while (s[i])
		ft_putchar_pf(f, s[i++]);
}

void	ft_putpading(t_fmt *f, char c, int n)
{
	while (n-- > 0)
		ft_putchar_pf(f, c);
}

char	*ft_utoa_base(unsigned long n, const char *base, char *buf)
{
	int		i;
	size_t	base_len;

	base_len = ft_strlen(base);
	i = 20;
	buf[i] = '\0';
	if (n == 0)
		buf[--i] = '0';
	while (n)
	{
		buf[--i] = base[n % base_len];
		n /= base_len;
	}
	return (buf + i);
}
