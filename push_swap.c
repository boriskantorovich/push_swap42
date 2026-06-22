/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:12:15 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/19 13:14:52 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	free_all(t_stack *a, t_stack *b, t_ops *ops)
{
	free(a);
	free(b);
	free(ops);
}

int	push_swap(int *input, int size, int flag)
{
	t_stack	*a;
	t_stack	*b;
	t_ops	*ops;
	int		isbench;
	double	disorder;

	if (!input)
		return (-1);
	a = init_stack(size);
	b = init_stack(size);
	isbench = ((flag - 3) % 2 == 0);
	ops = init_ops(flag, isbench);
	if (!a || !b || !ops)
	{
		free_all(a, b, ops);
		return (-1);
	}
	fill_stack(a, input, size);
	disorder = compute_disorder(a);
	dispatch(a, b, ops, flag);
	bench(ops, disorder, isbench);
	clear_all(a, b, ops);
	return (0);
}
