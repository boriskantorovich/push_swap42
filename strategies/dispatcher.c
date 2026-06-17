#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	int		i;
	int		j;
	long	mistakes;
	long	total_pairs;

	if (!a || a->size < 2)
		return (0.0);
	i = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < a->size - 1)
	{
		j = i + 1;
		while (j < a->size)
		{
			total_pairs++;
			if (a->numbers[i] > a->numbers[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((double)mistakes / (double)total_pairs);
}

static void	dispatch_small_helper(t_stack *a, t_stack *b, t_ops *ops)
{
	ops->strategy = ALG_SIMPLE;
	if (a->size == 2)
		sort_two(a, ops);
	else if (a->size == 3)
		sort_three(a, ops);
	else
		selection_sort(a, b, ops);
}

static void	dispatch_helper(t_stack *a, t_stack *b, t_ops *ops)
{
	const double	disorder = compute_disorder(a);

	if (a->size <= 5)
	{
		dispatch_small_helper(a, b, ops);
		return ;
	}
	if (disorder < 0.2)
	{
		ops->strategy = ALG_SIMPLE;
		selection_sort(a, b, ops);
	}
	else if (disorder < 0.5)
	{
		ops->strategy = ALG_MEDIUM;
		chunk_sort(a, b, ops);
	}
	else
	{
		ops->strategy = ALG_COMPLEX;
		radix_sort(a, b, ops);
	}
}

void	dispatch(t_stack *a, t_stack *b, t_ops *ops, int flag)
{
	flag -= 3;
	if (flag > 0 && flag % 2 == 0)
	{
		if (flag == 4)
		{
			ops->strategy = ALG_SIMPLE;
			selection_sort(a, b, ops);
		}
		else if (flag == 6)
		{
			ops->strategy = ALG_MEDIUM;
			chunk_sort(a, b, ops);
		}
		else if (flag == 8)
		{
			ops->strategy = ALG_COMPLEX;
			radix_sort(a, b, ops);
		}
		else 
			dispatch_helper(a, b, ops);
	}
	else 
		dispatch_helper(a, b, ops);
}
