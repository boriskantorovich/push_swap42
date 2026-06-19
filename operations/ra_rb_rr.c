/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 12:31:47 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/19 12:31:54 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *st)
{
	int	tmp;
	int	i;

	if (!st || st->count <= 1)
		return ;
	i = 0;
	tmp = st->numbers[i];
	while (i < (st->count - 1))
	{
		st->numbers[i] = st->numbers[i + 1];
		i++;
	}
	st->numbers[i] = tmp;
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
