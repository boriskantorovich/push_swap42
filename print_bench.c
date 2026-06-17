#include "push_swap.h"

static char	*strategy_name(int strategy)
{
	if (strategy == ALG_SIMPLE)
		return ("simple/O(n^2)");
	if (strategy == ALG_MEDIUM)
		return ("medium/chunk");
	if (strategy == ALG_COMPLEX)
		return ("complex/radix");
	if (strategy == ALG_ADAPTIVE)
		return ("adaptive");
	return ("none");
}

void	print_bench(t_ops *o, double disorder)
{
	dprintf(2,
		"[bench] disorder:  %.2f%%\n"
		"[bench] strategy:  %s total:  %d \n"
		"[bench] sa:  %d  sb:  %d  ss:  %d  pa:  %d  pb:  %d\n"
		"[bench] ra:  %d  rb:  %d  rr:  %d  rra:  %d  rrb:  %d  rrr:  %d\n",
		disorder * 100.0,
		strategy_name(o->strategy),
		o->total_ops,
		o->counter[OP_SA],
		o->counter[OP_SB],
		o->counter[OP_SS],
		o->counter[OP_PA],
		o->counter[OP_PB],
		o->counter[OP_RA],
		o->counter[OP_RB],
		o->counter[OP_RR],
		o->counter[OP_RRA],
		o->counter[OP_RRB],
		o->counter[OP_RRR]);
}

void	bench(t_ops *o, double disorder, int isbench)
{
	if (isbench)
		print_bench(o, disorder);
}
