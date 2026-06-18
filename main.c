#include "push_swap.h"

int	main(int argc, char **argv)
{
	const int	size = argc - parse_offset(parse_flags(argv)) - 1;
	int			flag;
	int			*input;

	if (size <= 0)
		return (0);
	flag = parse_flags(argv);
	input = validate_values(argc, argv, size);
	if (!input)
		return (print_error());
	if (validate_array(input, size) == 2)
	{
		free(input);
		return (print_error());
	}
	if (validate_array(input, size) == 0)
	{
		free(input);
		return (0);
	}
	rank_array(input, size);
	push_swap(input, size, flag);
	free(input);
	return (0);
}
