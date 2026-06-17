/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:01:00 by bkantoro          #+#    #+#             */
/*   Updated: 2026/05/11 20:08:06 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getnblen(long nb)
{
	size_t	len;

	len = 1;
	while (nb >= 10)
	{
		++len;
		nb = nb / 10;
	}
	return (len);
}

static void	ft_writenb(char *res, long nb, int sign, int len)
{
	if (!res)
		return ;
	res[len] = '\0';
	while (len > sign)
	{
		res[--len] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (sign)
		res[0] = '-';
}

char	*ft_itoa(int n)
{
	char	*res;
	long	nb;
	int		len;
	int		sign;

	nb = n;
	sign = 0;
	len = 0;
	if (nb < 0)
	{
		sign = 1;
		len++;
		nb = -nb;
	}
	len = len + ft_getnblen(nb);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	ft_writenb(res, nb, sign, len);
	return (res);
}
