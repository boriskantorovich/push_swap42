#include "push_swap.h"

t_ops	*init_ops(int flag, int isbench)
{
	t_ops	*new;

	new = malloc(sizeof(t_ops));
	if (!new)
		return (NULL);
	ft_bzero(new->counter, sizeof(t_ops));
	new->flag = flag;
	new->isbench = isbench;
	return (new);
}

void	do_op(t_ops *ops, int op, char *name)
{
	write(1, name, ft_strlen(name));
	ops->counter[op]++;
	ops->total_ops++;
}
