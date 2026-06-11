/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:36:20 by bkantoro          #+#    #+#             */
/*   Updated: 2026/05/12 12:36:52 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*t1;
	const unsigned char	*t2;

	if (!s1 || !s2 || !n)
		return (0);
	t1 = (const unsigned char *)s1;
	t2 = (const unsigned char *)s2;
	while (--n && *t1 && *t1 == *t2)
	{
		t1++;
		t2++;
	}
	return (*t1 - *t2);
}
