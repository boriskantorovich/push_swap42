/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:30:09 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/16 11:33:07 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	int		i;
	int		j;
	long	mistakes;
	long	total_pairs;

	if (!a || a->size < 2)
		return (0.0);
	i = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < a->size - 1)
	{
		j = i + 1;
		while (j < a->size)
		{
			total_pairs++;
			if (a->numbers[i] > a->numbers[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((double)mistakes / (double)total_pairs);
}

void	dispatch_small_helper(t_stack *a, t_stack *b, t_stack *ops)
{
	ops->strategy = ALG_SIMPLE;
	if (a->size == 2)
		sort_two(a, ops);
	else if (a->size == 3)
		sort_three(a, ops);
	else
		selection_sort(a, b, ops);
}

void	dispatch(t_stack *a, t_stack *b, t_ops *ops)
{
	double	disorder;

	if (!a || a->size <= 1 || compute_disorder(a) == 0.0)
		return ;
	if (a->size <= 5)
	{
		dispatch_small_helper(a, b, ops);
		return ;
	}
	disorder = compute_disorder(a);
	if (disorder < 0.2)
		ops->strategy = ALG_SIMPLE;
	else if (disorder < 0.5)
		ops->strategy = ALG_MEDIUM;
	else
		ops->strategy = ALG_COMPLEX;
	if (ops->strategy == ALG_SIMPLE)
		selection_sort(a, b, ops);
	else if (ops->strategy == ALG_MEDIUM)
		chunk_sort(a, b, ops);
	else
		radix_sort(a, b, ops);
}
