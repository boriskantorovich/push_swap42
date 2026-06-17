/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:38:14 by bkantoro          #+#    #+#             */
/*   Updated: 2026/05/12 12:38:17 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s_len;
	size_t	d_len;

	if (!src)
		return (size);
	s_len = ft_strlen(src);
	if (!dst || !size)
		return (s_len);
	d_len = ft_strlen(dst);
	if (size <= d_len)
		return (size + s_len);
	return (d_len + ft_strlcpy(dst + d_len, src, size - d_len));
}
