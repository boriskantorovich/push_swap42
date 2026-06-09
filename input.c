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

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}

int	ft_digit_advanced(const char *nptr)
{
	if (*nptr == '-' && ft_isdigit((int)(*nptr)))
		nptr++;
	while (*nptr)
	{
		if (ft_isdigit((int)(*nptr)))
			nptr++;
		else
			return (0);
	}
	return (1);
}

int	ft_atol_helper(const char *nptr)
{
	unsigned long long	nb;
	int			sgn;

	nb = 0;
	sgn = 0;
	if (*nptr == '-')
	{
		nptr++;
		sgn = 1;
	}
		while (ft_isdigit((int)(*nptr)))
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
	int			sgn;

	nb = 0;
	sgn = 1;
	if (*nptr == '-')
	{
		sgn = -sgn;
		nptr++;
	}
	while (ft_isdigit((int)(*nptr)))
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

int cmpflag(char *arg)
{
	int i = 1;
	int j = 2;
	int h = 0;
	char *flags[]= {"gg", "simple", "medium", "complex", "adaptive", "bench"};
	while (flags[i])
	{
		while (arg[j] == flags[i][h])
		{
			if (arg[j] == '\0')
				return (i);
			h++;
			j++;
		}
		i++;
	}
	return (0);
}

int	flag_extractor(char **argv, int argc)
{
	int i = 1;
	int j = 0;
	while (argc - (argc -2) < 3)
	{
		if ((!argv[i][j] == '-' && argv[i][j +1] == '-'))
			return (0);
		else
		{
			int res = cmpflag(argv[i]);
			if (res)
				return (res);
		}
		i++;
	}
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
	int i;
	int j;

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
	int 	flag;
	int	*input;
	int 	i;
	int	j;
	int 	size;

	if (argc == 1)
		return (print_error());
	if (argc >= 2) 
	{
		i = argc;
		/* while (i < argc && flag_extractor(argv[i])) // save somehow */
		/* { */
		/* 	flag += flag_extractor(argv[i]); */
		/* 	i++; */
		/* } */
		flag_extractor(argv, argc);
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
