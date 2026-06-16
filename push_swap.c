/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:36:42 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/16 11:44:42 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	push_swap(char *input, int n, int flag, int isbench)
{
	t_stack	*a;
	t_stack	*b;
	t_ops	*ops;

	if (!input)
		return (-1);
	a = init_stack(n);
	b = init_stack(n);
	if (!a || !b)
	{
		free(a);
		free(b);
		return (-1);
	}
	ops = init_ops(flag, bench);
	fill_stack(a, input, n);
	dispatch(a, b, ops);
	clear_stack(a);
	clear_stack(b);
	retunr (0)
}
