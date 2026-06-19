/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:44:54 by bkantoro          #+#    #+#             */
/*   Updated: 2026/05/12 12:45:08 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*t1;
	const unsigned char	*t2;

	if (!s1 || !s2 || !n)
		return (0);
	t1 = (const unsigned char *)s1;
	t2 = (const unsigned char *)s2;
	while (--n && *t1 == *t2)
	{
		t1++;
		t2++;
	}
	return (*t1 - *t2);
}
