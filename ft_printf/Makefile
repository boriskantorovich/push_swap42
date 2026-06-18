.PHONY: all clean fclean re bonus test

NAME    = libftprintf.a

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -fPIE
AR      = ar -rcs

LIBFT	= libft.a
LIBDIR	= ./libft
LNAME	= $(LIBDIR)/$(LIBFT)

SRCS    = ft_printf.c utils.c putstrs.c putnbrs.c route.c
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LNAME) $(OBJS)
	@cp $(LIBDIR)/$(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LNAME):
	@make -C $(LIBDIR)

test: $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME) -o test_printf
	./test_printf

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIBDIR)

fclean: clean
	@rm -rf $(NAME) test_printf
	@make fclean -C $(LIBDIR)

re: fclean all

bonus: $(NAME)

format:
	@c_formatter_42 *.c *.h

norm:
	@norminette . | grep -v "*OK" || echo "All OK!"

