#include "push_swap.h"

int	get_max_pos(t_stack *st)
{
	int	i;
	int	max_pos;

	if (!st || !st->size)
		return (-1);
	i = 0;
	max_pos = 0;
	while (i < st->size)
	{
		if (st->numbers[max_pos] < st->numbers[i])
			max_pos = i;
		i++;
	}
	return (max_pos);
}
