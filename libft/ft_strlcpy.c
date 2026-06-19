/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:27:19 by bkantoro          #+#    #+#             */
/*   Updated: 2026/05/12 12:39:05 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	s_len;

	if (!src)
		return (0);
	s_len = ft_strlen(src);
	if (!dst || !size)
		return (s_len);
	while (*src && --size)
		*dst++ = *src++;
	*dst = '\0';
	return (s_len);
}
