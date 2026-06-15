#include "push_swap.h"

static void	swap_two(int *val, int *idx, int i, int j)
{
	ft_swap(&val[i], &val[j]);
	ft_swap(&idx[i], &idx[j]);
}

static void	qsort_pair(int *val, int *idx, int low, int high)
{
	int	i;
	int	j;
	int	pivot;

	if (low >= high)
		return ;
	pivot = val[(low + high) / 2];
	i = low;
	j = high;
	while (i <= j)
	{
		while (val[i] < pivot)
			i++;
		while (val[j] > pivot)
			j--;
		if (i <= j)
			swap_two(val, idx, i++, j--);
	}
	qsort_pair(val, idx, low, j);
	qsort_pair(val, idx, i, high);
}

static void	build_pairs(int *arr, int *val, int *idx, int n)
{
	int	i;

	if (!arr || !val || !idx)
		return ;
	i = 0;
	while (i < n)
	{
		val[i] = arr[i];
		idx[i] = i;
		i++;
	}
}

static void	apply_ranks(int *arr, int *idx, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		arr[idx[i]] = i;
		i++;
	}
}

int	rank_array(int *arr, int n)
{
	int	*val;
	int	*idx;

	if (!arr)
		return (-1);
	val = malloc(sizeof(int) * n);
	idx = malloc(sizeof(int) * n);
	if (!val || !idx)
	{
		free(val);
		free(idx);
		return (-1);
	}
	build_pairs(arr, val, idx, n);
	qsort_pair(val, idx, 0, n - 1);
	apply_ranks(arr, idx, n);
	free(val);
	free(idx);
	return (0);
}
