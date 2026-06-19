/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:37:06 by bkantoro          #+#    #+#             */
/*   Updated: 2026/05/12 12:37:10 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*found;

	if (!s)
		return (NULL);
	found = NULL;
	while (*s)
	{
		if (*s == (char)c)
			found = (char *)s;
		s++;
	}
	if (*s == (char)c)
		found = (char *)s;
	return (found);
}
