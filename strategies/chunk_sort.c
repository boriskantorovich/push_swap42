#include "push_swap.h"

static void	chunk_sort_a(t_stack *a, t_stack *b, t_ops *ops, int chunk_size, int min_idx, int max_idx)
{
	while (a->count > 0)
	{
		if (a->numbers[0] >= min_idx && a->numbers[0] < max_idx)
		{
			pb(a, b, ops);
			if (b->numbers[0] < (min_idx + (chunk_size / 2)))
				rb(b, ops);
		}
		else
			ra(a, ops);
		if (b->count == max_idx)
		{
			min_idx += chunk_size;
			max_idx += chunk_size;
		}
	}
}

static void	chunk_sort_b(t_stack *a, t_stack *b, t_ops *ops)
{
	int	max_pos;

	while (b->count > 0)
	{
		max_pos = get_max_pos(b);
		if (max_pos <= b->count / 2)
		{
			while (max_pos > 0)
			{
				rb(b, ops);
				max_pos--;
			}
		}
		else
		{
			while (max_pos < b->count)
			{
				rrb(b,ops);
				max_pos++;
			}
		}
		pa(a, b, ops);
	}
}

void	chunk_sort(t_stack *a, t_stack *b, t_ops *ops)
{
	int	chunk_size;
	int	min_idx;
	int	max_idx;

	if (!a || !b )
		return ;
	chunk_size = sqrt(a->count);
	min_idx = 0;
	max_idx = chunk_size;
	chunk_sort_a(a, b, ops, chunk_size, min_idx, max_idx);
	chunk_sort_b(a, b, ops);
}

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	i = 1;
	while (i <= nb / i)
		i++;
	return (i - 1);
}
