/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:04:40 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/19 13:33:27 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	chunk_sort_a(t_stack **stack_pack, t_ops *ops, int chunk_size,
		int *min_max_idx)
{
	while (stack_pack[0]->count > 0)
	{
		if (stack_pack[0]->numbers[0] >= min_max_idx[0]
			&& stack_pack[0]->numbers[0] < min_max_idx[1])
		{
			pb(stack_pack[0], stack_pack[1], ops);
			if (stack_pack[1]->numbers[0] < (min_max_idx[0] + (chunk_size / 2)))
				rb(stack_pack[1], ops);
		}
		else
			ra(stack_pack[0], ops);
		if (stack_pack[1]->count == min_max_idx[1])
		{
			min_max_idx[0] += chunk_size;
			min_max_idx[1] += chunk_size;
		}
	}
}

static void	chunk_sort_b(t_stack *a, t_stack *b, t_ops *ops)
{
	int	max_pos;

	while (b->count > 0)
	{
		max_pos = get_max_pos(b);
		if (max_pos <= b->count / 2)
		{
			while (max_pos > 0)
			{
				rb(b, ops);
				max_pos--;
			}
		}
		else
		{
			while (max_pos < b->count)
			{
				rrb(b, ops);
				max_pos++;
			}
		}
		pa(a, b, ops);
	}
}

void	chunk_sort(t_stack *a, t_stack *b, t_ops *ops)
{
	int		chunk_size;
	int		min_max_idx[2];
	t_stack	*stack_pack[2];

	stack_pack[0] = a;
	stack_pack[1] = b;
	if (!a || !b)
		return ;
	chunk_size = ft_sqrt(a->count);
	min_max_idx[0] = 0;
	min_max_idx[1] = chunk_size;
	chunk_sort_a(stack_pack, ops, chunk_size, min_max_idx);
	chunk_sort_b(a, b, ops);
}
