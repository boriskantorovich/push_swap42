/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:07:40 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/19 13:07:42 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "push_swap.h"

# define OP_SA 0
# define OP_SB 1
# define OP_SS 2
# define OP_PA 3
# define OP_PB 4
# define OP_RA 5
# define OP_RB 6
# define OP_RR 7
# define OP_RRA 8
# define OP_RRB 9
# define OP_RRR 10

typedef struct s_ops	t_ops;
typedef struct s_stack	t_stack;

void		do_op(t_ops *ops, int op, char *name);
t_ops		*init_ops(int flag, int isbench);

int			clear_stack(t_stack *stack);
int			fill_stack(t_stack *stack, int *input, int n);
t_stack		*init_stack(int n);

void		sa(t_stack *a, t_ops *ops);
void		sb(t_stack *b, t_ops *ops);
void		ss(t_stack *a, t_stack *b, t_ops *ops);
void		pa(t_stack *a, t_stack *b, t_ops *ops);
void		pb(t_stack *a, t_stack *b, t_ops *ops);
void		ra(t_stack *a, t_ops *ops);
void		rb(t_stack *b, t_ops *ops);
void		rr(t_stack *a, t_stack *b, t_ops *ops);
void		rra(t_stack *a, t_ops *ops);
void		rrb(t_stack *b, t_ops *ops);
void		rrr(t_stack *a, t_stack *b, t_ops *ops);

#endif
