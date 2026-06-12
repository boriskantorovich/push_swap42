#include "push_swap.h"

int	print_error(char *err)
{
	printf("Error: %s\n", err);
	return (1);
}

int	validate_sorted(int *input, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (input[i] > input[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	validate_repeat(int *input, int n)
{
	int	i;
	int	j;

	i = 0;
	n -= 1;
	while (i <= n)
	{
		j = i + 1;
		while (j <= n)
		{
			printf("i: %d, j: %d\n", input[i], input[j]);
			if (input[i] == input[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
