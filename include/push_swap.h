/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:14:36 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/19 13:26:26 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "limits.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# include "ft_printf.h"
# include "operations.h"
# include "strategies.h"
# include "utils.h"

typedef struct s_stack
{
	int		*numbers;
	int		count;
	int		size;
}			t_stack;

typedef struct s_ops
{
	int		counter[11];
	int		total_ops;
	int		flag;
	char	*strategy;
	int		isbench;
}			t_ops;

int			push_swap(int *input, int size, int flag);

#endif
