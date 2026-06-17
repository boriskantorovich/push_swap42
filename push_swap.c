#include "push_swap.h"

int	push_swap(int *input, int size, int flag)
{
	t_stack	*a;
	t_stack	*b;
	t_ops	*ops;
	int		isbench;

	if (!input)
		return (-1);
	a = init_stack(size);
	b = init_stack(size);
	if (!a || !b)
	{
		free(a);
		free(b);
		return (-1);
	}
	isbench = ((flag - 3) % 2 == 0);
	ops = init_ops(flag, isbench);
	fill_stack(a, input, size);
	const double disorder = compute_disorder(a);
	dispatch(a, b, ops, flag);
	bench(ops, disorder, isbench);
	clear_stack(a);
	clear_stack(b);
	return (0);
}
