#include "push_swap.h"

int	helper_flag(char *value)
{
	int			i;
	const char	*values[] = {" ", " ", "--simple", "--bench", "--medium", " ",
			"--complex", " ", "--adaptive"}; //even 2,4,6,8 odd 1,3,5,7,9


	i = 2;
	if (!value)
		return (0);
	while (i < 9)
	{
		if (!ft_strcmp(value, values[i]))
			return (i);
		i++;
	}
	return (0);
}

int	parse_flags(char **argv)
{
	int	res;
	int	tmp;

	res = 0;
	tmp = helper_flag(argv[1]);
	if (tmp == 0)
		return (0);
	res = tmp + res;
	if (argv[2] && argv[2][0] == '-' && argv[2][1] == '-')
	{
		tmp = helper_flag(argv[2]);
		if (tmp == 0 || tmp == res || (tmp != 0 && res != 0 && ((res + tmp)
					% 2 == 0)))
			return (0);
		res += tmp;
	}
	return (res);
}

int	parse_offset(int flag)
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
