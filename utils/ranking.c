/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:09:41 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/19 13:09:43 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_two(int *val, int *idx, int i, int j)
{
	ft_swap(&val[i], &val[j]);
	ft_swap(&idx[i], &idx[j]);
}

static void	qsort_pair(int *val, int *idx, int low, int high)
{
	int	i;
	int	j;
	int	pivot;

	if (low >= high)
		return ;
	pivot = val[(low + high) / 2];
	i = low;
	j = high;
	while (i <= j)
	{
		while (val[i] < pivot)
			i++;
		while (val[j] > pivot)
			j--;
		if (i <= j)
			swap_two(val, idx, i++, j--);
	}
	qsort_pair(val, idx, low, j);
	qsort_pair(val, idx, i, high);
}

static void	build_pairs(int *input, int *val, int *idx, int size)
{
	int	i;

	if (!input || !val || !idx)
		return ;
	i = 0;
	while (i < size)
	{
		val[i] = input[i];
		idx[i] = i;
		i++;
	}
}

static void	apply_ranks(int *input, int *idx, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		input[idx[i]] = i;
		i++;
	}
}

int	rank_array(int *input, int size)
{
	int	*val;
	int	*idx;

	if (!input)
		return (-1);
	val = malloc(sizeof(int) * size);
	idx = malloc(sizeof(int) * size);
	if (!val || !idx)
	{
		free(val);
		free(idx);
		return (-1);
	}
	build_pairs(input, val, idx, size);
	qsort_pair(val, idx, 0, size - 1);
	apply_ranks(input, idx, size);
	free(val);
	free(idx);
	return (0);
}
