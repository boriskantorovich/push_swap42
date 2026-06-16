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
# include "libft.h"
# include "limits.h"
# include "stdio.h"
# include "string.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

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

# define ALG_SIMPLE 1
# define ALG_MEDIUM 2
# define ALG_COMPLEX 3
# define ALG_ADAPTIVE 4

typedef struct s_stack
{
	int	*numbers;
	int	size;
	int	n;
}		t_stack;

typedef struct s_ops
{
	int	counter[11];
	int	total_ops;
	int	flag;
	int	strategy;
	int	isbench;
}		t_ops;

int		clear_stack(t_stack *stack);
int		ft_digit_advanced(const char *nptr);
int		ft_atol_helper(const char *nptr);
long	ft_atol(const char *nptr);
int		print_error(void);
int		flag_extractor(char *arg);
int		push_swap(int *input, int n, int flag, int isbench);
int		found_repeats(int *input, int n);
int		is_sorted(int *input, int n);
int		main(int argc, char **argv);
int		find_pos(t_stack *st, int value);
int		get_max_pos(t_stack *st);
double	compute_disorder(t_stack *a);
int		rank_array(int *arr, int n);
void	dispatch(t_stack *a, t_stack *b, t_ops *ops);
void	selection_sort(t_stack *a, t_stack *b, t_ops *ops);
void	radix_sort(t_stack *a, t_stack *b, t_ops *ops);
void	chunk_sort(t_stack *a, t_stack *b, t_ops *ops);
void	sort_two(t_stack *a, t_ops *ops);
void	sort_three(t_stack *a, t_ops *ops);
t_stack	*init_stack(int n);
int		fill_stack(t_stack *stack, int *input, int n);
void	do_op(t_ops *ops, int op, char *name);
t_ops	*init_ops(int flag, int isbench);
void	print_bench(t_ops *o, double disorder);
void	swap_first_pair(t_stack *st);
void	sa(t_stack *a, t_ops *ops);
void	sb(t_stack *b, t_ops *ops);
void	ss(t_stack *a, t_stack *b, t_ops *ops);
void	pa(t_stack *a, t_stack *b, t_ops *ops);
void	pb(t_stack *a, t_stack *b, t_ops *ops);
void	ra(t_stack *a, t_ops *ops);
void	rb(t_stack *b, t_ops *ops);
void	rr(t_stack *a, t_stack *b, t_ops *ops);
void	rra(t_stack *a, t_ops *ops);
void	rrb(t_stack *b, t_ops *ops);
void	rrr(t_stack *a, t_stack *b, t_ops *ops);

#endif
