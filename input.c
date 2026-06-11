/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:33:16 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/11 12:16:30 by milnicki         ###   ########.fr       */
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

void	push_swap(int *input , int flag)
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

int	cmpstr(char *value)
{
	int i;
    const char *values[] = {" ", " ", "--simple", "--bench", "--medium", " ", "--complex", " ", "--adaptive"};
	
	i = 2;
	if (!value)
		return (0);
	while (i < 9)
    {
        if (!strcmp(value, values[i]))
            return (i);
		i++;
    }
    return (0);
}	

int	flags(char **argv)
{
	int res;
	int tmp;

	res = 0;
	tmp = cmpstr(argv[1]);
	if (tmp == 0)
		return (0);
	res = tmp + res;
	if (argv[2])
	{
		if (argv[2][0] == '-' && argv[2][1] == '-')
		{
			tmp = cmpstr(argv[2]);
			if (tmp == 0 || tmp == res || (tmp != 0 && res != 0 && ((res + tmp) % 2 == 0)))
				return (0);
			res += tmp;
		}
	}
    return (res);
}

int	main(int argc, char **argv)
{
	int 	flag;
	/* int	*input; */
	/* int	j; */
	/* int 	size; */

	if (argc == 1)
		return (print_error());
	if (argc > 1) 
	{
		/* while (argv[i] && i < 3) */
		flag = flags(argv);
			/* flag = flags(argv[2]); */
		if (flag == -1)
			printf("ERRROR");
		printf("%d", flag);
		/* input = (int *)malloc(sizeof(int) * size); */
		/* if (!input) */
		/* 	return (print_error()); */
		/* j = 0; */
		/* while (i < argc) */
		/* { */
		/* 	if (!ft_digit_advanced(argv[i])) */
		/* 	{ */
		/* 		free(input); */
		/* 		return (print_error()); */
		/* 	} */
		/* 	if (!ft_atol_helper(argv[i])) */
		/* 	{ */
		/* 		free(input); */
		/* 				return (print_error()); */
		/* 	} */
		/* 	input[j] = ft_atol(argv[i]); */
		/* 	j++; */
		/* 	i++; */
		/* } */
		/* if (!found_repeats(input, size)) */
		/* { */
		/* 	if (!is_sorted(input, size)) */
		/* 		push_swap(input, flag); */
		/* 	else */
		/* 		return (0); */
		/* } */
		/* else */
		/* 	return (print_error()); */
	}
	return (0);
}
