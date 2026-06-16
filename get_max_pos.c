/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:28:21 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/16 13:54:21 by milnicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_pos(t_stack *stack)
{
	int	i;
	int	max_pos;

	if (!stack || !stack->count)
		return (-1);
	i = 0;
	max_pos = 0;
	while (i < stack->count)
	{
		if (stack->numbers[max_pos] < stack->numbers[i])
			max_pos = i;
		i++;
	}
	return (max_pos);
}
