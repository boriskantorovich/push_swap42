#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		flag;
	int		offset;
	int		size;
	int		i;
	int		*input;
	int		j;
	int		g = 0;

	if (argc == 1)
		return (print_error("not enough args"));
	flag = count_flags(argv); 
	offset = count_offset(flag);
	size = argc - offset - 1;
	printf("flag: %d\noffset: %d\n", flag, offset);
	if (size > 1)
	{
		input = (int *)malloc(sizeof(int) * size);
		i = argc - size;
		j = 0;
		while (i < argc)
		{
			if (validate_arg(argv[i]))
			{
				input[j] = ft_atoi(argv[i]);
				i++;
				j++;
			}
			else
				return (print_error("wrong input"));
		}
		if (validate_repeat(input, size))
			print_error("repeat found");
		if (validate_sorted(input, size))
			print_error("sorted input");
		while (g < size)
		{
			printf("%d\n", input[g]);
			g++;
		}
	}
	return (0);
}
