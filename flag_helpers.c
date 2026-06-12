#include "push_swap.h"

int	compare_flag(char *value)
{
	int			i;
	const char	*values[] = {" ", " ", "--simple", "--bench",
		"--medium", " ", "--complex", " ", "--adaptive"};

	i = 2;
	if (!value)
		return (0);
	while (i < 9)
	{
		if (!strcmp(value, values[i]))
			return (i);
		i++;
	}
	return (0);
}

int	count_flags(char **argv)
{
	int	res;
	int	tmp;

	res = 0;
	tmp = compare_flag(argv[1]);
	if (tmp == 0)
		return (0);
	res = tmp + res;
	if (argv[2])
	{
		if (argv[2][0] == '-' && argv[2][1] == '-')
		{
			tmp = compare_flag(argv[2]);
			if (tmp == 0 || tmp == res || (tmp != 0 && res != 0 
					&& ((res + tmp) % 2 == 0)))
				return (0);
			res += tmp;
		}
	}
	return (res);
}

int	count_offset(int flag)
{
	if (flag != 0)
	{
		if (flag == 3 || (flag % 2 == 0)) 
			return (1);
		else if (flag % 2 == 1)
			return (2);
	}
	return (0);
}
