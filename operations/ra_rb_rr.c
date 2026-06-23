/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 12:31:47 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/23 11:39:40 by milnicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (!stack || stack->count <= 1)
		return ;
	i = 0;
	tmp = stack->numbers[i];
	while (i < (stack->count - 1))
	{
		stack->numbers[i] = stack->numbers[i + 1];
		i++;
	}
	stack->numbers[i] = tmp;
}

void	ra(t_stack *a, t_ops *ops)
{
	if (!a || a->count <= 1)
		return ;
	rotate(a);
	do_op(ops, OP_RA, "ra\n");
}

void	rb(t_stack *b, t_ops *ops)
{
	if (!b || b->count <= 1)
		return ;
	rotate(b);
	do_op(ops, OP_RB, "rb\n");
}

void	rr(t_stack *a, t_stack *b, t_ops *ops)
{
	if (!a || !b)
		return ;
	rotate(a);
	rotate(b);
	do_op(ops, OP_RR, "rr\n");
}
