/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:09:34 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/19 13:09:36 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validate_sorted(int *input, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (input[i] > input[i + 1])
			return (1);
		i++;
	}
	return (0);
}

static int	validate_repeat(int *input, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (input[i] == input[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_stack(int *input, int size)
{
	if (validate_repeat(input, size) == 1)
		return (2);
	if (validate_sorted(input, size) == 1)
		return (1);
	return (0);
}
