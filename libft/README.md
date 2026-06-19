*This project has been created as part of the 42 curriculum by bkantoro.*

# Libft
 
## Description
 
Libft is a 42 project where the goal is to recreate a personal C library.
It contains reimplementations of standard C library functions, as well as additional utility functions for string manipulation, memory management, file descriptor output, and linked list operations.
 
### Functions included
- **Libc functions:** ft_memset, ft_bzero, ft_memcpy, ft_memmove, ft_memchr, ft_memcmp, ft_strlen, ft_strdup, ft_strchr, ft_strrchr, ft_strnstr, ft_strncmp, ft_strlcpy, ft_strlcat, ft_atoi, ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint, ft_toupper, ft_tolower, ft_calloc
- **Additional functions:** ft_substr, ft_strjoin, ft_strtrim, ft_split, ft_itoa, ft_strmapi, ft_striteri, ft_putchar_fd, ft_putstr_fd, ft_putendl_fd, ft_putnbr_fd
- **Linked lists:** ft_lstnew, ft_lstadd_front, ft_lstsize, ft_lstlast, ft_lstadd_back, ft_lstdelone, ft_lstclear, ft_lstiter, ft_lstmap
 
## Instructions
 
```bash
make all    # compile the library
make clean  # remove object files
make fclean # remove object files and library
make re     # recompile
```

## Resources
- [Oceano's videos on linked lists](https://www.youtube.com/watch?v=mkZYMKwKkvI)
- [libft-unit-test](https://github.com/alelievr/libft-unit-test/) for testing
- [libftTester](https://github.com/Tripouille/libftTester) for more testing
- Claude to understand how the Makefile works and ask questions on specific function failures, as well as to make this README file and additional custom tests

