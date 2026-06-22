/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 12:31:11 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/19 12:31:13 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ops	*init_ops(int flag, int isbench)
{
	t_ops	*new;

	new = malloc(sizeof(t_ops));
	if (!new)
		return (NULL);
	ft_bzero(new, sizeof(t_ops));
	new->flag = flag;
	new->isbench = isbench;
	return (new);
}

void	do_op(t_ops *ops, int op, char *name)
{
	write(1, name, ft_strlen(name));
	ops->counter[op]++;
	ops->total_ops++;
}
