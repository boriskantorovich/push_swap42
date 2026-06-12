#include "push_swap.h"

int	find_pos(t_stack *st, int value)
{
	int	size;

	if (!st)
		return (-1);
	size = value + 1;
	while(size--)
	{
		if (st->numbers[size] == value)
			return (size);	
	}
	return (-1);
}

void	selection_sort(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	while (b->size)
	{
		if (!(b->numbers[0] == (b->size - 1)))
		{
			if (find_pos(b, b->size - 1) > ((b->size - 1) / 2))
				ra(a);
			else
				rra(a);
		}
		else
			pa(a, b);
		b->size--;
	}
}

int	get_max_pos(t_stack *st)
{
	int	i;
	int	max_pos;

	if (!st)
		return (-1);
	i = 0;
	max_pos = 0;
	while (i < st->size - 1)
	{
		if (st->numbers[max_pos] < st->numbers[i])
			max_pos = i;
		i++;
	}
	return (max_pos);
}

int	find_max_bit(int a)
{
	int n;

	n = 0;
	while (a)
	{
		n++;
		a = a / 2;
	}
	return (n);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bit;
	int	cur_bit;
	int	i;

	max_bit = find_max_bit(a->numbers[get_max_pos(a)]);
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
