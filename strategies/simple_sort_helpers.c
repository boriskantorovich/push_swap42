/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:34:10 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/16 20:28:36 by milnicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_two(t_stack *a, t_ops *ops)
{
	if (a->numbers[0] > a->numbers[1])
		sa(a, ops);
}

void	sort_three(t_stack *a, t_ops *ops)
{
	int	x;
	int	y;
	int	z;

	x = a->numbers[0];
	y = a->numbers[1];
	z = a->numbers[2];
	if (x < y && y < z)
		return ;
	if (x > y && y < z && x < z)
		sa(a, ops);
	else if (x > y && y > z)
	{
		sa(a, ops);
		rra(a, ops);
	}
	else if (x > y && y < z && x > z)
		ra(a, ops);
	else if (x < y && y > z && x > z)
		rra(a, ops);
	else
	{
		rra(a, ops);
		sa(a, ops);
	}
}
