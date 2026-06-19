/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:07:31 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/19 13:07:33 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "push_swap.h"

int	parse_flags(char **argv);
int	parse_offset(int flag);
int	validate_array(int *input, int size);
int	*validate_values(int argc, char **argv, int size);
int	rank_array(int *input, int size);

#endif
