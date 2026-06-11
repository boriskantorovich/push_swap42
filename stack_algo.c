#include "push_swap.h"





void	radix_sort(t_stack *a, t_stack *b)
{
	int max_bit = find_max_bit(a->numbers);
	int cur_bit = 1;
	int i;

	if (!a || !b)
		return ;
	i = 0;
	while (cur_bit <= max_bit)
	{
		while (i < (a->size - 1))
		{
			if (a->numbers[i] >> cur_bit == 1)
				ra(&a);
			else
				pb(&a, &b);
			i++;
		}
		while (b->size--)
			pa(&a, &b);
		++cur_bit;
	}
}



