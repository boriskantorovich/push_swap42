/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_api.c                                   :+:      :+:    :+:   */
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

	cr_assert_not_null(s, "init_stack(5) returned NULL");
	cr_assert_eq(s->n, 5, "capacity should be 5, got %d", s->n);
	cr_assert_eq(s->size, 0, "new stack should be empty, got %d", s->size);

	clear_stack(s);
}
Test(stack, sa_sb_all)
{
	int      nums[] = {1, 2, 3};
	t_stack *s = init_stack(3);
	fill_stack(s, nums, 3);

	dump("before swap", s);
	sa(s);
	dump("after swap", s);
	
	dump("before swap", s);
	sa(s);
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
	t_stack *s = init_stack(6);

	sa(NULL); 
	sb(NULL); 
	ra(NULL); 
	rb(NULL); 
	rr(NULL, s); 
	rr(s, NULL); 
	rra(NULL); 
	rrb(NULL); 
	rrr(NULL, s); 
	rrr(s, NULL); 
	pa(s, NULL); 
	pa(NULL, s); 
	pb(s, NULL); 
	pb(NULL, s); 
	cr_assert(1, "reached here = no crash");
}

Test(guards, swap_single_element_noop)
{
	int      nums[] = {42};
	t_stack *s = init_stack(3);
	fill_stack(s, nums, 1);

	sa(s);
	cr_expect_eq(s->numbers[0], 42, "single element must be untouched");
	cr_expect_eq(s->size, 1, "size must stay 1");
	clear_stack(s);
}

Test(guards, push_to_full_stack_noop)
{
	int      a_nums[] = {1, 2, 3};
	int      b_nums[] = {9};
	t_stack *a = init_stack(3);   /* cap 3, will be full */
	t_stack *b = init_stack(3);
	fill_stack(a, a_nums, 3);
	fill_stack(b, b_nums, 1);

	pa(a, b);   /* a is full — should refuse */
	cr_expect_eq(a->size, 3, "full stack must not grow past capacity");
	clear_stack(a);
	clear_stack(b);
}

/* ── swap: oracle = manually swap top two in the mirror ───── */

Test(swap, matches_reference_random)
{
	srand(42);   /* fixed seed = reproducible failures */
	for (int trial = 0; trial < 200; trial++)
	{
		int      mirror[10];
		t_stack *s = random_stack(10, 10, mirror);

		sa(s);

		/* reference: what SHOULD sa do? You define it.
		   Swap mirror[0] and mirror[1] — IF that's what sa means
		   in your layout. Adjust if your "top" is elsewhere. */
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

/* ── push round-trip: pb then pa should restore original ──── */

Test(push, pb_then_pa_is_identity)
{
	srand(7);
	for (int trial = 0; trial < 200; trial++)
	{
		int      mirror[10];
		t_stack *a = random_stack(10, 10, mirror);
		t_stack *b = init_stack(10);

		pb(b, a);   /* move a's top to b */
		pa(a, b);   /* move it back */

		if (!stacks_match(a, mirror, 10))
			dump("a after pb+pa (should equal original)", a);
		cr_expect(stacks_match(a, mirror, 10),
			"trial %d: pb then pa did not restore a", trial);
		clear_stack(a);
		clear_stack(b);
	}
}

/* ── rotate: top moves to bottom (you confirm the direction) ─ */

Test(rotate, ra_is_reversible_with_rra)
{
	srand(99);
	for (int trial = 0; trial < 200; trial++)
	{
		int      mirror[8];
		t_stack *s = random_stack(8, 8, mirror);

		ra(s);    /* adjust args to your real signature */
		rra(s);   /* rra should undo ra */

		if (!stacks_match(s, mirror, 8))
			dump("after ra+rra (should be unchanged)", s);
		cr_expect(stacks_match(s, mirror, 8),
			"trial %d: ra then rra did not restore", trial);
		clear_stack(s);
	}
}
