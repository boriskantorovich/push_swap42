/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 12:57:03 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/12 17:30:28 by milnicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

/// TEST INCLUDES

# include "stdio.h"
# include "limits.h"
# include "string.h"
# include "assert.h"

typedef	struct	s_stack
{
	int	*numbers;
	size_t	size;
	size_t	n;
}		t_stack;

void	ft_swap(int *a, int *b);

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	pa(t_stack *stack, int input);
t_stack	*init_stack(int n);
int	fill_stack(t_stack *stack, int *input, int n);
void	clear_stack(t_stack *stack);

int		compare_flag(char *value);
int		count_flags(char **argv);
int		count_offset(int flag);
int		ft_atoi(const char *nptr);
int		validate_arg(const char *nptr);
int		print_error(char *err);
int		validate_sorted(int *input, int size);
int		validate_repeat(int *input, int n);



#endif
