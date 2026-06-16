/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:33:42 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/16 17:10:06 by milnicki         ###   ########.fr       */
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
	int	count;

	if (!a || !b)
		return ;
	max_bit = find_max_bit(a->numbers[get_max_pos(a)]);
	cur_bit = 0;
	count = a->count;
	while (cur_bit < max_bit)
	{
		i = 0;
		while (i < count)
		{
			if ((a->numbers[0] >> cur_bit) & 1)
				ra(a, ops);
			else
				pb(a, b, ops);
			i++;
		}
		while (b->count > 0)
			pa(a, b, ops);
		++cur_bit;
	}
}
