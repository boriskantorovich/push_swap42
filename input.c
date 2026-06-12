/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:33:16 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/12 16:45:30 by milnicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}

void print_error(void)
{
	printf("Error\n");
	return (-1);
}

int	found_repeats(int *input, int n)
{
	int	i;
	int	j;

	i = 0;
	n -= 1;
	while (i <= n)
	{
		j = i + 1;
		while (j <= n)
		{
			/* printf("i: %d, j: %d\n", input[i], input[j]); */
			if (input[i] == input[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(int *input, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (input[i] > input[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	cmpstr(char *value)
{
	int i;
    const char *values[] = {" ", " ", "--simple", "--bench", "--medium", " ", "--complex", " ", "--adaptive"};
	/*						 0	  1	       2 	      3		      4 	  5 	  	6	    7 		   8 */	
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

int helper(int flag)
{
	if (flag != 0)
	{
		if (flag == 3 || (flag % 2 == 0)) 
			return (1);
		else if (flag % 2 == 1)
			return (2);
	}
	return (0);
}

int atol_helper(const char *nptr)
{
	unsigned long long	nb;
	int			sgn;

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

int	ft_atol(const char *nptr)
{
	int			nb;
	int			sgn;

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

int	main(int argc, char **argv)
{
	int 	flag;
	int		offset;
	int		size;
	int		i;
	int		*input;
	int		j;

	if (argc == 1)
		return (print_error("not enough args"));

	flag = flags(argv);
	offset = helper(flag);
	size = argc - offset - 1;
	printf("flag: %d\noffset: %d\n", flag, offset);

	if (size > 1) 
	{
		input = (int *)malloc(sizeof(int) * size);
		i = argc - size;
		j = 0;

		while (i < argc)
		{
			if (atol_helper(argv[i]))
			{
				input[j] = ft_atol(argv[i]);
				i++;
				j++;
			}
			else
				return (print_error("wrong input"));
		}
		if (found_repeats(input, size))
		{
			printf("repeats");
			return (0);
		}
		if (is_sorted(input,size))
		{
			printf("sorted");
			return (0); 
		}
		int g = 0;
		while(g < size)
		{
			printf("%d\n", input[g]);
			g++;
		}

	}
	return (0);
}
