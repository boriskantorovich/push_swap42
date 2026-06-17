#ifndef STRATEGIES_H
# define STRATEGIES_H

# include "push_swap.h"

# define ALG_SIMPLE "Simple"
# define ALG_MEDIUM "Medium"
# define ALG_COMPLEX "Complex"
# define ALG_ADAPTIVE "Adaptive/"

void	dispatch(t_stack *a, t_stack *b, t_ops *ops, int flag);
void	radix_sort(t_stack *a, t_stack *b, t_ops *ops);
void	selection_sort(t_stack *a, t_stack *b, t_ops *ops);
void	chunk_sort(t_stack *a, t_stack *b, t_ops *ops);
void	sort_two(t_stack *a, t_ops *ops);
void	radix_sort(t_stack *a, t_stack *b, t_ops *ops);
void	sort_three(t_stack *a, t_ops *ops);
/* void	swap_first_pair(t_stack *st); */

#endif
