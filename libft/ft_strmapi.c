/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:33:30 by bkantoro          #+#    #+#             */
/*   Updated: 2026/05/12 12:38:00 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	i;

	if (!s || !f)
		return (NULL);
	res = ft_strdup(s);
	if (!res)
		return (NULL);
	i = 0;
	while (res[i])
	{
		res[i] = f(i, res[i]);
		i++;
	}
	return (res);
}
