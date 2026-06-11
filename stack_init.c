/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:17:21 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/09 14:16:05 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->numbers = NULL;
	new->size = 0;
	new->n = n;
	return (new);
}

int	fill_stack(t_stack *stack, int *input, int n)
{
	size_t	i;

	i = 0;
	if (!stack || !input || !n)
		return (0);
	stack->numbers = malloc(sizeof(int) * n);
	if (!stack->numbers)
		return (0);
	while (i < n)
	{
		stack->numbers[i] = input[i];
		i++;
	}
	stack->size = n;
	return (1);
}

void	clear_stack(t_stack *stack)
{
	free(stack->numbers);
	free(stack);
}
