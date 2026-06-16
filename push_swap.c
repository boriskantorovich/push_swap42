/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:36:42 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/16 17:54:42 by milnicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int *input, int size, int flag)
{
	t_stack	*a;
	t_stack	*b;
	t_ops	*ops;
	int		isbench;

	if (!input)
		return (-1);
	a = init_stack(size);
	b = init_stack(size);
	if (!a || !b)
	{
		free(a);
		free(b);
		return (-1);
	}
	isbench = ((flag - 3) % 2 == 0);
	/* printf("isbench: [%d]\n", isbench); */
	/* printf("flag: [%d]\n", flag); */
	ops = init_ops(flag, isbench);
	fill_stack(a, input, size);
	dispatch(a, b, ops);
	clear_stack(a);
	clear_stack(b);
	return (0);
}
