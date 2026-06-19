/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:08:45 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/19 13:10:21 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	helper_flag(char *value)
{
	int			i;
	const char	*values[] = {" ", " ", " ", "--bench", "--simple", " ", \
			"--medium", " ", "--complex", " ", "--adaptive"};

	i = 2;
	if (!value)
		return (0);
	while (i < 11)
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
