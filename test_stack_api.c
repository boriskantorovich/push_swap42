/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_api.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:34:00 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/09 14:27:46 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_print(t_stack *test, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", test->numbers[i]);
	}
}

int	main(void)
{
	t_stack *test;
	int n = 5;
	int test_nb[] = {100, 213, 12, INT_MAX, INT_MIN};	
	test = init_stack(n);
	fill_stack(test, test_nb, n);
	test_print(test, n);
	sa(test);	
	test_print(test, n);
	sb(test);	
	test_print(test, n);
	clear_stack(test);
}
