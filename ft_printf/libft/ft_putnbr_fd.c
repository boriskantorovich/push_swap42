/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:42:28 by bkantoro          #+#    #+#             */
/*   Updated: 2026/05/12 12:42:43 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	t;

	t = n;
	if (t < 0)
	{
		ft_putchar_fd('-', fd);
		t = -t;
	}
	while (t >= 10)
	{
		ft_putnbr_fd(t / 10, fd);
		t = t % 10;
	}
	ft_putchar_fd(t + '0', fd);
}
