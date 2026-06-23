/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 12:31:37 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/23 11:40:23 by milnicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	revrotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (!stack || stack->count <= 1)
		return ;
	tmp = stack->numbers[stack->count - 1];
	i = stack->count - 1;
	while (i > 0)
	{
		stack->numbers[i] = stack->numbers[i - 1];
		i--;
	}
	stack->numbers[0] = tmp;
}

void	rra(t_stack *a, t_ops *ops)
{
	if (!a || a->count <= 1)
		return ;
	revrotate(a);
	do_op(ops, OP_RRA, "rra\n");
}

void	rrb(t_stack *b, t_ops *ops)
{
	if (!b || b->count <= 1)
		return ;
	revrotate(b);
	do_op(ops, OP_RRB, "rrb\n");
}

void	rrr(t_stack *a, t_stack *b, t_ops *ops)
{
	if (!a || !b || a->count <= 1 || b->count <= 1)
		return ;
	revrotate(a);
	revrotate(b);
	do_op(ops, OP_RRR, "rrr\n");
}
