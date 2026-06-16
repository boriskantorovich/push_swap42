/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:29:50 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/16 11:29:52 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* todo - placeholder */
void	chunk_sort(t_stack *a, t_stack *b, t_ops *ops)
{
	if (!a || !b)
		return ;
	radix_sort(a, b, ops);
}
