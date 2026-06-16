#include "push_swap.h"

static void	revrotate(t_stack *st)
{
	int	tmp;
	int	i;

	if (!st || st->count <= 1)
		return ;
	tmp = st->numbers[st->count - 1];
	i = st->count - 1;
	while (i > 0)
	{
		st->numbers[i] = st->numbers[i - 1];
		i--;
	}
	st->numbers[0] = tmp;
}

void	rra(t_stack *a, t_ops *ops)
{
	if (!a || a->count <= 1)
		return ;
	revrotate(a);
	do_op(ops, OP_RRA, "rra\n");
}

void	rrb(t_stack *b, t_ops *ops)
{
	if (!b || b->count <= 1)
		return ;
	revrotate(b);
	do_op(ops, OP_RRB, "rrb\n");
}

void	rrr(t_stack *a, t_stack *b, t_ops *ops)
{
	if (!a || !b || a->count <= 1 || b->count <= 1)
		return ;
	revrotate(a);
	revrotate(b);
	do_op(ops, OP_RRR, "rrr\n");
}
