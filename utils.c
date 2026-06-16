#include "push_swap.h"

int	print_error(char *err)
{
	printf("Error: %s\n", err);
	return (1);
}

static int	validate_sorted(int *input, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (input[i] > input[i + 1])
			return (1);
		i++;
	}
	return (0);
}

static int	validate_repeat(int *input, int size)
{
	int	i;
	int	j;

	i = 0;
	size -= 1;
	while (i <= size)
	{
		j = i + 1;
		while (j <= size)
		{
			if (input[i] == input[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	if (!a || !b)
		return ;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	validate_array(int *input, int size)
{
	if (validate_repeat(input, size) == 1)
		return (2);
	if (validate_sorted(input, size) == 1)
		return (1);
	return (0);
}
