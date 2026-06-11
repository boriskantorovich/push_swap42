/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:19:33 by bkantoro          #+#    #+#             */
/*   Updated: 2026/05/12 12:45:30 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*t;

	if (!s || !n)
		return (NULL);
	t = (const unsigned char *)s;
	while (n--)
	{
		if (*t == (unsigned char)c)
			return ((void *)t);
		t++;
	}
	return (NULL);
}
