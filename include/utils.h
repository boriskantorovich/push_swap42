/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:08:25 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/19 13:08:27 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef UTILS_H
# define UTILS_H

# include "push_swap.h"

void	bench(t_ops *o, double disorder, int isbench);
int		rank_array(int *input, int size);
int		validate_array(int *input, int size);
int		*validate_values(int argc, char **argv, int size);
int		parse_offset(int flag);
int		parse_flags(char **argv);
int		print_error(void);

#endif
