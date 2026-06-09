/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_api.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:17:21 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/09 14:06:22 by bkantoro         ###   ########.fr       */
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

void	pa(t_stack *stack, int input)
{
	size_t i;

	if (!stack || stack->size == stack->n)
		return ;
	i = 0;
	stack->size++;
	while(i < (stack->size - 1))
	{
		stack->numbers[i + 1] = stack->numbers[i];
		i++;
	}
	stack->numbers[0] = input;
}

