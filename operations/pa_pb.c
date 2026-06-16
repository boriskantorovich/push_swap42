#include "push_swap.h"

static void	grow_down(t_stack *st, int new)
{
	int	i;

	if (!st || st->count == st->size)
		return ;
	st->count++;
	i = st->count - 1;
	while (i > 0)
	{
		st->numbers[i] = st->numbers[i - 1];
		i--;
	}
	st->numbers[0] = new;
}

static void	shrink_up(t_stack *stack)
{
	int	i;

	if (!stack || stack->count == 0)
		return ;
	i = 0;
	while (i < (stack->count - 1))
	{
		stack->numbers[i] = stack->numbers[i + 1];
		i++;
	}
	stack->count--;
}

static void	push(t_stack *dst, t_stack *src)
{
	if (!dst || !src || dst->count == dst->size || src->count == 0)
		return ;
	grow_down(dst, src->numbers[0]);
	shrink_up(src);
}

void	pa(t_stack *a, t_stack *b, t_ops *ops)
{
	if (!a || !b || b->count == 0)
		return ;
	push(a, b);
	do_op(ops, OP_PA, "pa\n");
}

void	pb(t_stack *a, t_stack *b, t_ops *ops)
{
	if (!a || !b || a->count == 0)
		return ;
	push(b, a);
	do_op(ops, OP_PB, "pb\n");
}
