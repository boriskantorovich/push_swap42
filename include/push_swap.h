#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "limits.h"
# include "string.h"
# include "bsd/string.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*numbers;
	int	count;
	int	size;
}		t_stack;

typedef struct s_ops
{
	int		counter[11];
	int		total_ops;
	int		flag;
	char	*strategy;
	int		isbench;
}		t_ops;

# include "operations.h"
# include "strategies.h"
# include "utils.h"
# include "ft_printf.h"

int		push_swap(int *input, int size, int flag);

int		parse_flags(char **argv);
int		parse_offset(int flag);
int		validate_array(int *input, int size);
int		*validate_values(int argc, char **argv, int size);

int		rank_array(int *input, int size);

t_stack	*init_stack(int n);
int		fill_stack(t_stack *stack, int *input, int n);
int		clear_stack(t_stack *stack);
void	print_bench(t_ops *o, double disorder);
void	bench(t_ops *o, double disorder, int isbench);
double	compute_disorder(t_stack *a);

#endif
