#include "push_swap.h"

void	selection_sort(t_stack *a, t_stack *b)
{
	while (b->size)
	{
		if (!(b->numbers[0] == (b->size - 1)))
		{
			if (find_pos(b->size - 1) > ((b->size - 1) / 2))
				ra(a);
			else
				rra(a);
		}
		else
			pa(a, b);
		b->size--;
	}
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bit;
	int	cur_bit;
	int	i;

	max_bit = find_max_bit(a->numbers);
	cur_bit = 1;
	if (!a || !b)
		return ;
	i = 0;
	while (cur_bit <= max_bit)
	{
		while (i < (a->size - 1))
		{
			if (a->numbers[i] >> cur_bit == 1)
				ra(a);
			else
				pb(a, b);
			i++;
		}
		while (b->size--)
			pa(a, b);
		++cur_bit;
	}
}
