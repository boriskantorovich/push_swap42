#include "push_swap.h"

/* todo - placeholder */
void	chunk_sort(t_stack *a, t_stack *b, t_ops *ops)
{
	if (!a || !b)
		return ;
	radix_sort(a, b, ops);
}
