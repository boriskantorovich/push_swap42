/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:08:53 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/19 13:08:55 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}

static int	ft_atoi(const char *nptr)
{
	int	nb;
	int	sgn;

	nb = 0;
	sgn = 1;
	if (*nptr == '-')
	{
		sgn = -1;
		nptr++;
	}
	while (ft_isdigit((int)(*nptr)))
	{
		nb = nb * 10 + (*nptr - '0');
		nptr++;
	}
	return (sgn * nb);
}

static int	validate_int(const char *nptr)
{
	if (!*nptr)
		return (0);
	if (*nptr == '-' && ft_isdigit(*(nptr + 1)))
		nptr++;
	while (*nptr)
	{
		if (!ft_isdigit(*nptr))
			return (0);
		nptr++;
	}
	return (1);
}

static int	validate_value(const char *nptr)
{
	unsigned long long	nb;
	int					sgn;

	nb = 0;
	sgn = 1;
	if (*nptr == '-')
	{
		sgn = -1;
		nptr++;
	}
	while (ft_isdigit((int)(*nptr)))
	{
		nb = nb * 10 + (*nptr - '0');
		if (sgn == 1 && nb > INT_MAX)
			return (0);
		else if (sgn == -1 && nb > (unsigned long long)INT_MAX + 1)
			return (0);
		nptr++;
	}
	return (1);
}

int	*validate_values(int argc, char **argv, int size)
{
	int	jndex;
	int	index;
	int	*input;

	index = argc - size;
	jndex = 0;
	input = (int *)malloc(sizeof(int) * size);
	if (!input)
		return (NULL);
	while (index < argc)
	{
		if (validate_int(argv[index]) && validate_value(argv[index]))
			input[jndex++] = ft_atoi(argv[index++]);
		else
		{
			free(input);
			return (NULL);
		}
	}
	return (input);
}
