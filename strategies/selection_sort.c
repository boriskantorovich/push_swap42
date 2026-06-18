/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:34:00 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/16 20:24:24 by milnicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "push_swap.h"

int	find_pos(t_stack *st, int value)
{
	int	i;

	if (!st)
		return (-1);
	i = 0;
	while (i < st->count)
	{
		if (st->numbers[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	selection_sort(t_stack *a, t_stack *b, t_ops *ops)
{
	int	pos;
	int	min;

	if (!a || !b)
		return ;
	min = 0;
	while (a->count > 3)
	{
		pos = find_pos(a, min);
		if (pos <= (a->count / 2))
			while (pos-- > 0)
				ra(a, ops);
		else
			while (pos++ < a->count)
				rra(a, ops);
		pb(a, b, ops);
		min++;
	}
	if (a->count == 3)
		sort_three(a, ops);
	else if (a->count == 2)
		sort_two(a, ops);
	while (b->count > 0)
		pa(a, b, ops);
}
