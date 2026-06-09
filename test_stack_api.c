/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_api.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:34:00 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/09 14:14:10 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_stack *test;
	int n = 5;
	int test_nb[] = {100, 213, 12, INT_MAX, INT_MIN};	
	test = init_stack(n);
	fill_stack(test, test_nb, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", test->numbers[i]);
	}
	sa(test);	
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", test->numbers[i]);
	}
	clear_stack(test);
}
