/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:33:31 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/16 11:33:32 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_op(t_ops *ops, int op, char *name)
{
	write(1, name, ft_strlen(name));
	ops->counter[op]++;
	ops->total_ops++;
}
