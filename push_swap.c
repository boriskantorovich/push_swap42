#include "push_swap.h"

int	push_swap(int *input, int size, int flag)
{
	t_stack	*a;
	t_stack	*b;
	t_ops	*ops;
	int		isbench;
	double	disorder;

	if (!input)
		return (-1);
	a = init_stack(size);
	b = init_stack(size);
	isbench = ((flag - 3) % 2 == 0);
	ops = init_ops(flag, isbench);
	if (!a || !b || !ops)
	{
		free(a);
		free(b);
		free(ops);
		return (-1);
	}
	fill_stack(a, input, size);
	disorder = compute_disorder(a);
	dispatch(a, b, ops, flag);
	bench(ops, disorder, isbench);
	clear_stack(a);
	clear_stack(b);
	free(ops);
	return (0);
}
