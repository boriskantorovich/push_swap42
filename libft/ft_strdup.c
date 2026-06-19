/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:35:03 by bkantoro          #+#    #+#             */
/*   Updated: 2026/05/12 12:35:06 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s) + 1;
	res = malloc(size);
	if (!res)
		return (NULL);
	ft_memcpy(res, s, size);
	return (res);
}
