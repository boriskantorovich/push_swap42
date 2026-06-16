/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:33:42 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/16 11:33:43 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_bit(int a)
{
	int	n;

	n = 0;
	while (a)
	{
		n++;
		a = a / 2;
	}
	return (n);
}

void	radix_sort(t_stack *a, t_stack *b, t_ops *ops)
{
	int	max_bit;
	int	cur_bit;
	int	i;
	int	size;

	if (!a || !b)
		return ;
	max_bit = find_max_bit(a->numbers[get_max_pos(a)]);
	cur_bit = 0;
	size = a->size;
	while (cur_bit < max_bit)
	{
		i = 0;
		while (i < size)
		{
			if ((a->numbers[0] >> cur_bit) & 1)
				ra(a, ops);
			else
				pb(a, b, ops);
			i++;
		}
		while (b->size > 0)
			pa(a, b, ops);
		++cur_bit;
	}
}
