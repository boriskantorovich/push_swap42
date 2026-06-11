/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:12:04 by bkantoro          #+#    #+#             */
/*   Updated: 2026/05/11 19:27:02 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_tokencount(char const *s, char sep)
{
	size_t	tokens;

	tokens = 0;
	if (!s || !(*s))
		return (tokens);
	while (*s)
	{
		while (*s && (*s == sep))
			s++;
		if (*s)
			tokens++;
		while (*s && !(*s == sep))
			s++;
	}
	return (tokens);
}

static void	ft_freechararr(char **array, size_t size)
{
	char	*ptr;

	if (!array || !(*array))
		return ;
	ptr = *array;
	while (size--)
	{
		free((void *)ptr);
		ptr++;
	}
	free(array);
}

static void	ft_splitfill(char **token_vector, char const *s, char sep,
		size_t tokencount)
{
	size_t	len;

	if (!token_vector || !s || !(*s) || !tokencount)
		return ;
	while (*s && tokencount--)
	{
		len = 0;
		while (*s && (*s == sep))
			s++;
		while (*s && !(*s == sep))
		{
			s++;
			len++;
		}
		*token_vector = ft_substr(s - len, 0, len);
		if (!(*token_vector))
		{
			ft_freechararr(token_vector, tokencount);
			return ;
		}
		token_vector++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**token_vector;
	size_t	tokens;

	if (!s)
		return (NULL);
	tokens = ft_tokencount(s, c);
	token_vector = malloc(sizeof(char *) * (tokens + 1));
	if (!token_vector)
		return (NULL);
	token_vector[tokens] = NULL;
	if (!tokens)
		return (token_vector);
	ft_splitfill(token_vector, s, c, tokens);
	return (token_vector);
}
