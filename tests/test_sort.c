#include "push_swap.h"
#include <criterion/criterion.h>

static int	is_sorted_stack(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->numbers[i] > a->numbers[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	run_dispatch(int *vals, int n)
{
	t_stack	*a;
	t_stack	*b;
	t_ops	o;
	int		fd;

	rank_array(vals, n);
	a = init_stack(n);
	b = init_stack(n);
	fill_stack(a, vals, n);
	o = (t_ops){0};
	fd = dup(1);
	close(1);
	dispatch(a, b, &o);
	dup2(fd, 1);
	close(fd);
	cr_assert(is_sorted_stack(a), "Stack A not sorted (n=%d)", n);
	cr_assert_eq(b->size, 0, "Stack B not empty (n=%d)", n);
	cr_assert_eq(a->size, n, "Stack A lost elements (n=%d)", n);
	clear_stack(a);
	clear_stack(b);
}

Test(sort, reverse_inputs)
{
	int	n[5] = {2, 3, 5, 100, 500};
	int	*v;
	int	i;
	int	k;

	k = 0;
	while (k < 5)
	{
		v = malloc(sizeof(int) * n[k]);
		i = 0;
		while (i < n[k])
		{
			v[i] = n[k] - i;
			i++;
		}
		run_dispatch(v, n[k]);
		free(v);
		k++;
	}
}

Test(sort, already_sorted_noop)
{
	int	v[6] = {0, 1, 2, 3, 4, 5};

	run_dispatch(v, 6);
}

Test(sort, random_seeded)
{
	int	v[200];
	int	i;
	int	trial;

	srand(99);
	trial = 0;
	while (trial < 30)
	{
		i = 0;
		while (i < 200)
		{
			v[i] = (i * 11 + 1);
			i++;
		}
		i = 0;
		while (i < 200)
		{
			int t = v[i];
			int j = rand() % 200;
			v[i] = v[j];
			v[j] = t;
			i++;
		}
		run_dispatch(v, 200);
		trial++;
	}
}

Test(sort, radix_path_directly)
{
	int		v[50];
	t_stack	*a;
	t_stack	*b;
	t_ops	o;
	int		i;
	int		fd;

	i = 0;
	while (i < 50)
	{
		v[i] = 50 - i;
		i++;
	}
	rank_array(v, 50);
	a = init_stack(50);
	b = init_stack(50);
	fill_stack(a, v, 50);
	o = (t_ops){0};
	fd = dup(1);
	close(1);
	radix_sort(a, b, &o);
	dup2(fd, 1);
	close(fd);
	cr_assert(is_sorted_stack(a));
	cr_assert_eq(b->size, 0);
	clear_stack(a);
	clear_stack(b);
}
