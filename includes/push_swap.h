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

# include "libft.h"
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
	int	size;
	int	n;
}			t_stack;

void	clear_stack(t_stack *stack);
int	ft_digit_advanced(const char *nptr);
int	ft_atol_helper(const char *nptr);
long	ft_atol(const char *nptr);
int	print_error(void);
int	flag_extractor(char *arg);
void	push_swap(int *input, int flag);
int	found_repeats(int *input, int n);
int	is_sorted(int *input, int n);
int	main(int argc, char **argv);
int	find_pos(t_stack *st, int value);
void	selection_sort(t_stack *a, t_stack *b);
int	get_max_pos(t_stack *st);
int	find_max_bit(int a);
void	radix_sort(t_stack *a, t_stack *b);
void	grow_down(t_stack *stack, int new);
void	shrink_up(t_stack *stack);
void	push(t_stack *dst, t_stack *src);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	swap_first_pair(t_stack *st);
void	sa(t_stack *a);
void	sb(t_stack *b);
t_stack	*init_stack(int n);
int	fill_stack(t_stack *stack, int *input, int n);
void	rotate(t_stack *st);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	revrotate(t_stack *st);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif
