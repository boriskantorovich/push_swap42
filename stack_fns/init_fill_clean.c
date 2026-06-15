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

	if (n <= 0)
	{
		print_error();
		return (NULL);
	}
	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->numbers = malloc(sizeof(int) * n);
	if (!new->numbers)
	{
		free(new);
		return (NULL);
	}
	new->size = 0;
	new->n = n;
	return (new);
}

int	fill_stack(t_stack *stack, int *input, int n)
{
	int	i;

	i = 0;
	if (!stack || !input || !n || !stack->numbers)
		return (-1);
	while (i < n)
	{
		stack->numbers[i] = input[i];
		i++;
	}
	stack->size = n;
	return (0);
}

int	clear_stack(t_stack *stack)
{
	if (!stack)
		return (-1);
	free(stack->numbers);
	free(stack);
	return (0);
}
