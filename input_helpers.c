#include "push_swap.h"

static int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}

int	ft_atoi(const char *nptr)
{
	int			nb;
	int			sgn;

	nb = 0;
	sgn = 1;
	if (*nptr == '-')
	{
		sgn = -1;
		nptr++;
	}
	while (ft_isdigit((int)(*nptr)))
	{
		nb = nb * 10 + (*nptr - '0');
		nptr++;
	}
	return (sgn * nb);
}

int	validate_arg(const char *nptr)
{
	unsigned long long	nb;
	int					sgn;

	nb = 0;
	sgn = 1;
	if (*nptr == '-')
	{
		sgn = -1;
		nptr++;
	}
	while (ft_isdigit((int)(*nptr)))
	{
		nb = nb * 10 + (*nptr - '0');
		if (sgn == 1 && nb > INT_MAX)
			return (0);
		else if (sgn == -1 && nb > (unsigned long long)INT_MAX + 1)
			return (0);
		nptr++;
	}
	return (1);
}


