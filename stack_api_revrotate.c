/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_api.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:17:21 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/11 15:02:09 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revrotate(t_stack *st)
{
	int	tmp;
	int	i;

	if (!st || st->size <= 1)
		return ;
	tmp = st->numbers[st->size - 1];
	i = st->size - 1;
	while (i > 0)
	{
		st->numbers[i] = st->numbers[i - 1];
		i--;
	}
	st->numbers[0] = tmp;
}

void	rra(t_stack *a)
{
	if (!a)
		return ;
	revrotate(a);
}

void	rrb(t_stack *b)
{
	if (!b)
		return ;
	rotate (b);
}

void	rrr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	rra(a);
	rrb(b);
}
