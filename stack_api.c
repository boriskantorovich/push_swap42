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

void	sa(t_stack *stack)
{
	if (stack->size > 1)
		ft_swap(&stack->numbers[0], &stack->numbers[1]);
}

void	sb(t_stack *stack)
{
	if (stack->size > 1)
		ft_swap(&stack->numbers[0], &stack->numbers[1]);
}

void	grow_down(t_stack *stack, int new)
{
	int i;

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
	int i;

	i = 0;
	if (!stack || stack->size == 0)
		return ;
	stack->size--;
	while (i < (stack->size - 1))
	{
		stack->numbers[i] = stack->numbers[i + 1];
		i++;
	}
}

void	pa(t_stack *a, t_stack *b)
{
	if (!a || !b || a->size == a->n)
		return ;
	grow_down(&a, b->numbers[0]);
	shrink_up(&b);
}

void	pb(t_stack *b, t_stack *a)
{
	if (!a || !b || a->size == a->n)
		return ;
	grow_down(&b, a->numbers[0]);
	shrink_up(&a);
}

void	ra(t_stack *a, t_stack *b)
{
	if (!a || !b || a->size == a->n)
		return ;
	grow_down(&a, b->numbers[0]);
	shrink_up(&b);
}

