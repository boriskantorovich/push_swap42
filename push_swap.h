/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 12:57:03 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/16 13:31:56 by milnicki         ###   ########.fr       */
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

typedef struct s_stack
{
	int		*numbers;
	size_t	size;
	size_t	n;
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

#endif
