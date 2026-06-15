/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_api_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:17:21 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/11 16:05:28 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	grow_down(t_stack *st, int new)
{
	int	i;

	if (!st || st->size == st->n)
		return ;
	st->size++;
	i = st->size - 1;
	while (i > 0)
	{
		st->numbers[i] = st->numbers[i - 1];
		i--;
	}
	st->numbers[0] = new;
}

static void	shrink_up(t_stack *stack)
{
	int	i;

	if (!stack || stack->size == 0)
		return ;
	i = 0;
	while (i < (stack->size - 1))
	{
		stack->numbers[i] = stack->numbers[i + 1];
		i++;
	}
	stack->size--;
}

static void	push(t_stack *dst, t_stack *src)
{
	if (!dst || !src || dst->size == dst->n || src->size == 0)
		return ;
	grow_down(dst, src->numbers[0]);
	shrink_up(src);
}

void	pa(t_stack *a, t_stack *b, t_ops *ops)
{
	if (!a || !b || b->size == 0)
		return ;
	push(a, b);
	do_op(ops, OP_PA, "pa\n");
}

void	pb(t_stack *a, t_stack *b, t_ops *ops)
{
	if (!a || !b || a->size == 0)
		return ;
	push(b, a);
	do_op(ops, OP_PB, "pb\n");
}
