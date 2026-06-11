/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_api_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:17:21 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/11 16:06:44 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_first_pair(t_stack *st)
{
	if (!st || st->size <= 1)
		return ;
	ft_swap(&st->numbers[0], &st->numbers[1]);
}

void	sa(t_stack *a)
{
	swap_first_pair(a);
}

void	sb(t_stack *b)
{
	swap_first_pair(b);
}

