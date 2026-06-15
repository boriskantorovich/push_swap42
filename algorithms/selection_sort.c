#include "push_swap.h"

int	find_pos(t_stack *st, int value)
{
	int	i;

	if (!st)
		return (-1);
	i = 0;
	while (i < st->size)
	{
		if (st->numbers[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	selection_sort(t_stack *a, t_stack *b, t_ops *ops)
{
	int	pos;
	int	min;

	if (!a || !b)
		return ;
	min = 0;
	while (a->size > 3)
	{
		pos = find_pos(a, min);
		if (pos <= (a->size / 2))
			while (pos-- > 0)
				ra(a, ops);
		else
			while (pos++ < a->size)
				rra(a, ops);
		pb(a, b, ops);
		min++;
	}
	sort_three(a, ops);
	while (b->size > 0)
		pa(a, b, ops);
}
