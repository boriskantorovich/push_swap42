/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_api_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:17:21 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/11 16:06:44 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_first_pair(t_stack *st)
{
	if (!st || st->size <= 1)
		return ;
	ft_swap(&st->numbers[0], &st->numbers[1]);
}

void	sa(t_stack *a, t_ops *ops)
{
	if (!a || a->size <= 1)
		return ;
	swap_first_pair(a);
	do_op(ops, OP_SA, "sa\n");
}

void	sb(t_stack *b, t_ops *ops)
{
	if (!b || b->size <= 1)
		return ;
	swap_first_pair(b);
	do_op(ops, OP_SB, "sb\n");
}

void	ss(t_stack *a, t_stack *b, t_ops *ops)
{
	if (!a || !b || a->size <= 1 || b->size <= 1)
		return ;
	swap_first_pair(a);
	swap_first_pair(b);
	do_op(ops, OP_SS, "ss\n");
}
