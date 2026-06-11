/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:33:16 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/09 19:40:53 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_digit_advanced(const char *nptr)
{
	if (*nptr == '-' && *(nptr + 1) >= '0' && *(nptr + 1) <= '9')
		nptr++;
	while (*nptr)
	{
		if (*nptr >= '0' && *nptr <= '9')
			nptr++;
		else
			return (0);
	}
	return (1);
}

int	ft_atol_helper(const char *nptr)
{
	unsigned long long	nb;
	int					sgn;

	nb = 0;
	sgn = 0;
	if (*nptr == '-')
	{
		nptr++;
		sgn = 1;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = nb * 10 + (*nptr - '0');
		if (!sgn && nb > INT_MAX)
			return (0);
		if (sgn && nb > (unsigned long long)INT_MAX + 1)
			return (0);
		nptr++;
	}
	return (1);
}

long	ft_atol(const char *nptr)
{
	unsigned long long	nb;
	int					sgn;

	nb = 0;
	sgn = 1;
	if (*nptr == '-')
	{
		sgn = -sgn;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = nb * 10 + (*nptr - '0');
		nptr++;
	}
	return (sgn * nb);
}

int	print_error(void)
{
	write(1, "Error\n", 6);
	return (-1);
}

int	flag_extractor(char *arg)
{
	if (!strcmp(arg, "--simple"))
		return (1);
	if (!strcmp(arg, "--medium"))
		return (2);
	if (!strcmp(arg, "--complex"))
		return (3);
	if (!strcmp(arg, "--adaptive"))
		return (4);
	if (!strcmp(arg, "--bench"))
		return (5);
	return (0);
}

void	push_swap(int *input, int flag)
{
	// ranking
	// input [12, 10, 13, 128] -> copy -> qsort -> [1, 0, 2, 3]
	((void)input);
	((void)flag);
}

int	found_repeats(int *input, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i <= n)
	{
		j = i + 1;
		while (j <= n)
		{
			if (input[i] == input[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(int *input, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		if (input[i] > input[i + 1])
			return (0);
		i++;
	}
	printf("sorted\n");
	return (1);
}

int	main(int argc, char **argv)
{
	int	flag;
	int	*input;
	int	i;
	int	j;
	int	size;

	if (argc == 1)
		return (print_error());
	if (argc >= 2)
	{
		i = 1;
		while (i < argc && flag_extractor(argv[i])) // save somehow
		{
			flag += flag_extractor(argv[i]);
			i++;
		}
		size = argc - i;
		input = (int *)malloc(sizeof(int) * size);
		if (!input)
			return (print_error());
		j = 0;
		while (i < argc)
		{
			if (!ft_digit_advanced(argv[i]))
			{
				free(input);
				return (print_error());
			}
			if (!ft_atol_helper(argv[i]))
			{
				free(input);
				return (print_error());
			}
			input[j] = ft_atol(argv[i]);
			j++;
			i++;
		}
		if (!found_repeats(input, size))
		{
			if (!is_sorted(input, size))
				push_swap(input, flag);
			else
				return (0);
		}
		else
			return (print_error());
	}
	return (0);
}
