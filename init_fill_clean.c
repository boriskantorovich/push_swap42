/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fill_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:17:21 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/16 19:34:28 by milnicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int size)
{
	t_stack	*new;

	if (size <= 0)
	{
		print_error();
		return (NULL);
	}
	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->numbers = malloc(sizeof(int) * size);
	if (!new->numbers)
	{
		free(new);
		return (NULL);
	}
	new->count = 0;
	new->size = size;
	return (new);
}

int	fill_stack(t_stack *stack, int *input, int size)
{
	int	i;

	i = 0;
	if (!stack || !input || !size || !stack->numbers)
		return (-1);
	while (i < size)
	{
		stack->numbers[i] = input[i];
		i++;
	}
	stack->count = size;
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
