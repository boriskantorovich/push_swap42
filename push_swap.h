/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 12:57:03 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/15 16:08:47 by milnicki         ###   ########.fr       */
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

int		parse_flags(char **argv);
int		parse_offset(int flag);
int		print_error(char *err);
int		validate_array(int *input, int size);
int		*validate_values(int argc, char **argv, int size);

#endif
