#ifndef STRATEGIES_H
# define STRATEGIES_H

# include "push_swap.h"

# define ALG_SIMPLE 4
# define ALG_MEDIUM 6
# define ALG_COMPLEX 8
# define ALG_ADAPTIVE 4

void	dispatch(t_stack *a, t_stack *b, t_ops *ops, int flag);
void	radix_sort(t_stack *a, t_stack *b, t_ops *ops);
void	selection_sort(t_stack *a, t_stack *b, t_ops *ops);
void	chunk_sort(t_stack *a, t_stack *b, t_ops *ops);
void	sort_two(t_stack *a, t_ops *ops);
void	radix_sort(t_stack *a, t_stack *b, t_ops *ops);
void	sort_three(t_stack *a, t_ops *ops);
/* void	swap_first_pair(t_stack *st); */

#endif
