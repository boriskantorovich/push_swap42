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

void	rotate(t_stack *st)
{
	int	tmp;
	int	i;

	if (!st || st->size <= 1)
		return ;
	i = 0;
	tmp = st->numbers[i];
	while (i < (st->size - 1))
	{
		st->numbers[i] = st->numbers[i + 1];
		i++;
	}
	st->numbers[i] = tmp;
}

void	ra(t_stack *a)
{
	if (!a)
		return ;
	rotate(a);
}

void	rb(t_stack *b)
{
	if (!b)
		return ;
	rotate (b);
}

void	rr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	ra(a);
	rb(b);
}
