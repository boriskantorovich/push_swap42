/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:07:57 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/19 13:08:19 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRATEGIES_H
# define STRATEGIES_H

# include "push_swap.h"

# define ALG_SIMPLE "Simple / O(n^2)"
# define ALG_MEDIUM "Medium / O(n√n)"
# define ALG_COMPLEX "Complex / O(n log n)"
# define ALG_ADA_SIMPLE "Adaptive / O(n^2)"
# define ALG_ADA_MEDIUM "Adaptive / O(n√n)"
# define ALG_ADA_COMPLEX "Adaptive / O(n log n)"

void	dispatch(t_stack *a, t_stack *b, t_ops *ops, int flag);
void	radix_sort(t_stack *a, t_stack *b, t_ops *ops);
void	selection_sort(t_stack *a, t_stack *b, t_ops *ops);
void	chunk_sort(t_stack *a, t_stack *b, t_ops *ops);
void	sort_two(t_stack *a, t_ops *ops);
void	radix_sort(t_stack *a, t_stack *b, t_ops *ops);
void	sort_three(t_stack *a, t_ops *ops);
int		get_max_pos(t_stack *stack);

#endif
