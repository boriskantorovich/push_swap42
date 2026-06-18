#include "push_swap.h"

int	print_error(void)
{
	write(2, "Error\n", 6);
	return (2);
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
	while (ss1[i] || ss2[i])
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}

