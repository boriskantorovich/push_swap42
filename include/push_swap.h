#ifndef PUSH_SWAP
# define PUSH_SWAP

/* # include "assert.h" */
# include "limits.h"
# include "stdio.h"
# include "string.h"
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
	int	counter[11];
	int	total_ops;
	int	flag;
	int	strategy;
	int	isbench;
}		t_ops;

# include "operations.h"
# include "strategies.h"

int		push_swap(int *input, int size, int flag);

int		parse_flags(char **argv);
int		parse_offset(int flag);
int		print_error(void);
int		validate_array(int *input, int size);
int		*validate_values(int argc, char **argv, int size);
int		rank_array(int *input, int size);

void	ft_swap(int *a, int *b);
void	ft_bzero(void *arr, size_t size);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);

t_stack	*init_stack(int n);
int		fill_stack(t_stack *stack, int *input, int n);
int		clear_stack(t_stack *stack);
int		get_max_pos(t_stack *stack);

void	dispatch(t_stack *a, t_stack *b, t_ops *ops);
void	print_bench(t_ops *o, double disorder);

#endif
