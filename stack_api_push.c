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

void	grow_down(t_stack *stack, int new)
{
	int	i;

	if (!stack || stack->size == stack->n)
		return ;
	i = 0;
	stack->size++;
	while (i < (stack->size - 1))
	{
		stack->numbers[i + 1] = stack->numbers[i];
		i++;
	}
	stack->numbers[0] = new;
}

void	shrink_up(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack || stack->size == 0)
		return ;
	while (i < (stack->size - 1))
	{
		stack->numbers[i] = stack->numbers[i + 1];
		i++;
	}
	stack->size--;
}

void	push(t_stack *dst, t_stack *src)
{
	if (!dst || !src || dst->size == dst->n || src->size == 0)
		return ;
	grow_down(dst, src->numbers[0]);
	shrink_up(src);
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
}

