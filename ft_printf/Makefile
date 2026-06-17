.PHONY: all clean fclean re bonus test

NAME    = libftprintf.a

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -fPIE
AR      = ar -rcs

LIBFT	= libft.a
LIBDIR	= ./libft

SRCS    = ft_printf.c utils.c putstrs.c putnbrs.c route.c
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBDIR)/$(LIBFT) $(OBJS)
	@cp $(LIBDIR)/$(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

LIBFT:
	@make -C $(LIBDIR)

test: $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME) -o test_printf
	./test_printf

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME) test_printf

re: fclean all

bonus: $(NAME)

format:
	@c_formatter_42 *.c *.h

norm:
	@norminette . | grep -v "*OK" || echo "All OK!"

