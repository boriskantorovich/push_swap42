#include "push_swap.h"
#include <criterion/criterion.h>

static t_stack	*make_stack(int *vals, int n)
{
	t_stack	*s;

	s = init_stack(n);
	fill_stack(s, vals, n);
	return (s);
}

Test(ops, sa_swaps_top_two_and_counts)
{
	int		v[3] = {1, 0, 2};
	t_stack	*s = make_stack(v, 3);
	t_ops	o = (t_ops){0};

	sa(s, &o);
	cr_assert_eq(s->numbers[0], 0);
	cr_assert_eq(s->numbers[1], 1);
	cr_assert_eq(o.counter[OP_SA], 1, "sa must count once");
	cr_assert_eq(o.total_ops, 1);
	clear_stack(s);
}

Test(ops, sa_noop_on_size_one)
{
	int		v[1] = {42};
	t_stack	*s = init_stack(1);
	t_ops	o = (t_ops){0};

	fill_stack(s, v, 1);
	sa(s, &o);
	cr_assert_eq(s->numbers[0], 42, "single element untouched");
	cr_assert_eq(o.total_ops, 0, "no print/count when nothing moved");
	clear_stack(s);
}

Test(ops, ra_then_rra_is_identity)
{
	int		v[5] = {4, 3, 2, 1, 0};
	t_stack	*s = make_stack(v, 5);
	t_ops	o = (t_ops){0};

	ra(s, &o);
	rra(s, &o);
	cr_assert_eq(s->numbers[0], 4);
	cr_assert_eq(s->numbers[4], 0);
	cr_assert_eq(o.counter[OP_RA], 1);
	cr_assert_eq(o.counter[OP_RRA], 1);
	clear_stack(s);
}

Test(ops, ra_moves_top_to_bottom)
{
	int		v[3] = {1, 2, 3};
	t_stack	*s = make_stack(v, 3);
	t_ops	o = (t_ops){0};

	ra(s, &o);
	cr_assert_eq(s->numbers[0], 2);
	cr_assert_eq(s->numbers[1], 3);
	cr_assert_eq(s->numbers[2], 1);
	clear_stack(s);
}

Test(ops, pb_then_pa_restores_and_counts)
{
	int		v[3] = {7, 8, 9};
	t_stack	*a = make_stack(v, 3);
	t_stack	*b = init_stack(3);
	t_ops	o = (t_ops){0};

	pb(a, b, &o);
	cr_assert_eq(b->size, 1);
	cr_assert_eq(a->size, 2);
	cr_assert_eq(b->numbers[0], 7, "pb moves A top to B top");
	pa(a, b, &o);
	cr_assert_eq(a->numbers[0], 7);
	cr_assert_eq(b->size, 0);
	cr_assert_eq(o.counter[OP_PB], 1);
	cr_assert_eq(o.counter[OP_PA], 1);
	clear_stack(a);
	clear_stack(b);
}

Test(ops, pb_noop_on_empty_source)
{
	t_stack	*a = init_stack(3);
	t_stack	*b = init_stack(3);
	t_ops	o = (t_ops){0};

	pb(a, b, &o);
	cr_assert_eq(o.total_ops, 0, "empty A: pb must not count");
	clear_stack(a);
	clear_stack(b);
}

Test(ops, null_guards_no_crash)
{
	t_ops	o = (t_ops){0};

	sa(NULL, &o);
	ra(NULL, &o);
	rra(NULL, &o);
	pa(NULL, NULL, &o);
	pb(NULL, NULL, &o);
	cr_assert_eq(o.total_ops, 0, "null ops count nothing");
}
