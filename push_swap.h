/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 12:57:03 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/16 14:35:05 by milnicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# include "stdio.h"
# include "limits.h"
# include "string.h"
# include "assert.h"

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
		int		*numbers;
		int		count;
		int		size;
}		t_stack;

typedef struct s_ops
{
		int	counter[11];
		int	total_ops;
		int	flag;
		int	strategy;
		int	isbench;
}		t_ops;

int		parse_flags(char **argv);
int		parse_offset(int flag);
int		print_error(char *err);
int		validate_array(int *input, int size);
int		*validate_values(int argc, char **argv, int size);

int		rank_array(int *input, int size);
void	ft_swap(int *a, int *b);
void	ft_bzero(void *arr, size_t size);
size_t	ft_strlen(const char *s);
int	ft_strcmp(const char *s1, const char *s2);


int		push_swap(int *input, int size, int flag);

t_stack		*init_stack(int n);
int			fill_stack(t_stack *stack, int *input, int n);
int			clear_stack(t_stack *stack);
int			get_max_pos(t_stack *stack);


t_ops		*init_ops(int flag, int isbench);
void		do_op(t_ops *ops, int op, char *name);

void	dispatch(t_stack *a, t_stack *b, t_ops *ops);
void	selection_sort(t_stack *a, t_stack *b, t_ops *ops);
void	radix_sort(t_stack *a, t_stack *b, t_ops *ops);
void	chunk_sort(t_stack *a, t_stack *b, t_ops *ops);
void	sort_two(t_stack *a, t_ops *ops);
void	sort_three(t_stack *a, t_ops *ops);

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
