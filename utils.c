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
	/* size -= 1; */
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

void	ft_bzero(void *arr, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	if (!arr)
		return ;
	ptr = (unsigned char *)arr;
	i = 0; 
	while (i < size)
		ptr[i++] = 0;
}

size_t	ft_strlen(const char *s)
{
	const char	*str;

	if (!s)
		return (0);
	str = s;
	while (*str)
		str++;
	return (str - s);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while ((ss1[i] || ss2[i]))
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}

int	validate_array(int *input, int size)
{
	if (validate_repeat(input, size) == 1)
		return (2);
	if (validate_sorted(input, size) == 1)
		return (1);
	return (0);
}
