#include "push_swap.h"

static int	find_max_bit(int a)
{
	int	n;

	n = 0;
	while (a)
	{
		n++;
		a = a / 2;
	}
	return (n);
}

int	get_max_pos(t_stack *stack)
{
	int	i;
	int	max_pos;

	if (!stack || !stack->count)
		return (-1);
	i = 0;
	max_pos = 0;
	while (i < stack->count)
	{
		if (stack->numbers[max_pos] < stack->numbers[i])
			max_pos = i;
		i++;
	}
	return (max_pos);
}

void	radix_sort(t_stack *a, t_stack *b, t_ops *ops)
{
	int	max_bit;
	int	cur_bit;
	int	i;
	int	count;

	if (!a || !b)
		return ;
	max_bit = find_max_bit(a->numbers[get_max_pos(a)]);
	cur_bit = 0;
	count = a->count;
	while (cur_bit < max_bit)
	{
		i = 0;
		while (i < count)
		{
			if ((a->numbers[0] >> cur_bit) & 1)
				ra(a, ops);
			else
				pb(a, b, ops);
			i++;
		}
		while (b->count > 0)
			pa(a, b, ops);
		++cur_bit;
	}
}
