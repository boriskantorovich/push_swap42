/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:35:39 by bkantoro          #+#    #+#             */
/*   Updated: 2026/05/12 12:51:19 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*t;

	if (!b || !n)
		return (b);
	t = (unsigned char *)b;
	while (n--)
		*t++ = (unsigned char)c;
	return (b);
}
