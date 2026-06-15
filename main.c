#include "push_swap.h"

int	main(int argc, char **argv)
{
	const int	size = argc - parse_offset(parse_flags(argv)) - 1;
	int			*input;


	/* STARTING WORKING ON RANKS */
	if (argc == 1)
		return (print_error("not enough args."));
	if (size > 500)
		return (print_error("more arguments then allowed."));
	if (size > 1)
	{
		input = validate_values(argc, argv, size);
		if (!input)
			return (print_error("not int value passed."));
		if (validate_array(input, size) == 2)
			return (print_error("repeat found."));
		if (validate_array(input, size) == 0)
			return (print_error("sorted order."));
	}
	return (0);
}
