#include "push_swap.h"

void	do_op(t_ops *ops, int op, char *name)
{
	write(1, name, ft_strlen(name));
	ops->counter[op]++;
	ops->total_ops++;
}
