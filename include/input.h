#ifndef INPUT_H
# define INPUT_H

# include "push_swap.h"

int	parse_flags(char **argv);
int	parse_offset(int flag);
int	validate_array(int *input, int size);
int	*validate_values(int argc, char **argv, int size);
int	rank_array(int *input, int size);

#endif
