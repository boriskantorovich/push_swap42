/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:11:43 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/23 11:28:03 by milnicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	bench(t_ops *o, double disorder, int isbench)
{
	int	whole;
	int	fraction;

	if (isbench)
	{
		whole = (int)(disorder * 100);
		fraction = (int)(disorder * 10000) % 100;
		ft_printf("[bench] disorder:  %d.%d%d%%\n"\
			"[bench] strategy:  %s\n[bench] total_ops:  %d\n"\
			"[bench] sa:  %d  sb:  %d  ss:  %d  pa:  %d  pb:  %d\n"\
			"[bench] ra:  %d  rb:  %d  rr:  %d  rra:  %d  rrb: %d  rrr:  %d\n"\
			, whole, fraction / 10, fraction % 10, \
			o->strategy, o->total_ops, o->counter[OP_SA], \
			o->counter[OP_SB], o->counter[OP_SS], o->counter[OP_PA], \
			o->counter[OP_PB], o->counter[OP_RA], o->counter[OP_RB], \
			o->counter[OP_RR], o->counter[OP_RRA], \
			o->counter[OP_RRB], o->counter[OP_RRR]);
	}
}

int	print_error(void)
{
	write(2, "Error\n", 6);
	return (2);
}
