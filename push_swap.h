/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 12:57:03 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/11 16:03:54 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "assert.h"
# include "limits.h"
# include "stdio.h"
# include "string.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int		*numbers;
	size_t	size;
	size_t	n;
}			t_stack;

void		ft_swap(int *a, int *b);

void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *b, t_stack *a);
t_stack		*init_stack(int n);
int			fill_stack(t_stack *stack, int *input, int n);
void		clear_stack(t_stack *stack);

#endif
