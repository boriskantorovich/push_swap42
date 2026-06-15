/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:34:00 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/09 14:27:46 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <criterion/criterion.h>
#include <criterion/logging.h>

static void dump(const char *label, t_stack *s)
{
	cr_log_info("%s (size=%d cap=%d):", label, s->size, s->n);
	for (int i = 0; i < s->size; i++)
		cr_log_info("  [%d] = %d", i, s->numbers[i]);
}

Test(stack, init_set)
{
	t_stack *s = init_stack(5);

	cr_assert_not_null(s, "init_stack returned NULL (malloc fail)");
	cr_assert_not_null(s->numbers, "init allocates the buffer");
	cr_assert_eq(s->n, 5, "capacity should be 5, got %d", s->n);
	cr_assert_eq(s->size, 0, "new stack should be empty, got %d", s->size);
	dump("new not filled stack", s);
	clear_stack(s);
}

Test(stack, fill_reads_exactly_n)
{
	int input[] = {10, 20, 30, 40, 99};
	t_stack *s = init_stack(5);
	int ret = fill_stack(s, input, 5);
	cr_assert_eq(ret, 0);
	cr_assert_eq(s->numbers[4], 99);
	cr_assert_eq(s->size, 5);
	clear_stack(s);
}

Test(stack, wront_set_init)
{
	t_ops o = (t_ops){0};
	t_stack *zero = init_stack(0);
	sa(zero, &o);
	clear_stack(zero);

	t_stack *neg = init_stack(-1000);
	sa(neg, &o);
	clear_stack(neg);
}

Test(invariant, push_conserves_total)
{
	int nums[10];
	t_ops o = (t_ops){0};
	for (int i = 0; i < 10; i++) nums[i] = i;
	t_stack *a = init_stack(10);
	t_stack *b = init_stack(10);
	fill_stack(a, nums, 10);
	srand(1);
	for (int op = 0; op < 1000; op++)
	{
		if (rand() % 2)
			pb(a, b, &o);
		else
			pa(a, b, &o);
		cr_assert_eq(a->size + b->size, 10,
			"op %d: total changed to %d", op, a->size + b->size);
		cr_assert_geq(a->size, 0, "a underflowed");
		cr_assert_geq(b->size, 0, "b underflowed");
	}
	clear_stack(a); clear_stack(b);
}

Test(stack, sa_sb_all)
{
	int      nums[] = {1, 2, 3};
	t_ops    o = (t_ops){0};
	t_stack *s = init_stack(3);
	fill_stack(s, nums, 3);

	dump("before swap", s);
	sa(s, &o);
	dump("after swap", s);

	dump("before swap", s);
	sa(s, &o);
	dump("after swap", s);
	clear_stack(s);
}

static t_stack *random_stack(int cap, int n, int *mirror)
{
	t_stack *s = init_stack(cap);
	int     *tmp = malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		tmp[i] = (rand() % 2000) - 1000;
	fill_stack(s, tmp, n);
	for (int i = 0; i < n; i++)
		mirror[i] = s->numbers[i];
	free(tmp);
	return s;
}

static int stacks_match(t_stack *s, int *expected, int n)
{
	if (s->size != n)
		return 0;
	for (int i = 0; i < n; i++)
		if (s->numbers[i] != expected[i])
			return 0;
	return 1;
}

Test(guards, null_does_not_crash)
{
	int      nums[] = {100, INT_MIN, 1, 2, INT_MAX, 10};
	t_ops    o = (t_ops){0};
	t_stack *s = init_stack(6);
	fill_stack(s, nums, 6);

	sa(NULL, &o);
	sb(NULL, &o);
	ra(NULL, &o);
	rb(NULL, &o);
	rr(NULL, s, &o);
	rr(s, NULL, &o);
	rra(NULL, &o);
	rrb(NULL, &o);
	rrr(NULL, s, &o);
	rrr(s, NULL, &o);
	pa(s, NULL, &o);
	pa(NULL, s, &o);
	pb(s, NULL, &o);
	pb(NULL, s, &o);
	cr_assert(1, "reached here = no crash");
	clear_stack(s);
}

Test(guards, swap_single_element_noop)
{
	int      nums[] = {42};
	t_ops    o = (t_ops){0};
	t_stack *s = init_stack(3);
	fill_stack(s, nums, 1);

	sa(s, &o);
	cr_expect_eq(s->numbers[0], 42, "single element must be untouched");
	cr_expect_eq(s->size, 1, "size must stay 1");
	clear_stack(s);
}

Test(guards, push_to_full_stack_noop)
{
	int      a_nums[] = {1, 2, 3};
	int      b_nums[] = {9};
	t_ops    o = (t_ops){0};
	t_stack *a = init_stack(3);
	t_stack *b = init_stack(3);
	fill_stack(a, a_nums, 3);
	fill_stack(b, b_nums, 1);

	pa(a, b, &o);
	cr_expect_eq(a->size, 3, "full stack must not grow past capacity");
	clear_stack(a);
	clear_stack(b);
}

Test(swap, matches_reference_random)
{
	t_ops o = (t_ops){0};
	srand(42);
	for (int trial = 0; trial < 200; trial++)
	{
		int      mirror[10];
		t_stack *s = random_stack(10, 10, mirror);

		sa(s, &o);
		int t = mirror[0];
		mirror[0] = mirror[1];
		mirror[1] = t;

		if (!stacks_match(s, mirror, 10))
			dump("MISMATCH after sa", s);
		cr_expect(stacks_match(s, mirror, 10),
			"trial %d: sa diverged from reference", trial);
		clear_stack(s);
	}
}

Test(push, pb_then_pa_is_identity)
{
	t_ops o = (t_ops){0};
	srand(7);
	for (int trial = 0; trial < 200; trial++)
	{
		int      mirror[10];
		t_stack *a = random_stack(10, 10, mirror);
		t_stack *b = init_stack(10);

		pb(a, b, &o);
		pa(a, b, &o);

		if (!stacks_match(a, mirror, 10))
			dump("a after pb+pa (should equal original)", a);
		cr_expect(stacks_match(a, mirror, 10),
			"trial %d: pb then pa did not restore a", trial);
		clear_stack(a);
		clear_stack(b);
	}
}

Test(rotate, ra_is_reversible_with_rra)
{
	t_ops o = (t_ops){0};
	srand(99);
	for (int trial = 0; trial < 200; trial++)
	{
		int      mirror[8];
		t_stack *s = random_stack(8, 8, mirror);

		ra(s, &o);
		rra(s, &o);

		if (!stacks_match(s, mirror, 8))
			dump("after ra+rra (should be unchanged)", s);
		cr_expect(stacks_match(s, mirror, 8),
			"trial %d: ra then rra did not restore", trial);
		clear_stack(s);
	}
}
