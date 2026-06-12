.PHONY: 	all clean fclean re test ret FORCE

NAME 		= push_swap

CC 		= gcc
CFLAGS 		= -Wall -Wextra -Werror
INCLUDES 	= -Iincludes

LIBFTDIR 	= ./libft
LIBFTNAME 	= libft.a
LIBFT		= $(LIBFTDIR)/$(LIBFTNAME)
LFLAGS		= -L$(LIBFTDIR) -l$(patsubst lib%, %, $(LIBFTNAME:.a=))

TESTDIR	 	= ./tests

SRCS 		= helpers.c \
		  stack_algo.c \
		  stack_api_push.c \
		  stack_api_swap.c \
		  stack_init.c \
		  stack_api.c
OBJ 		= $(SRCS:.c=.o)

all: 		$(NAME)

$(NAME): 	$(OBJ) $(LIBFT)
		@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)

test:
	@$(MAKE) -C $(TESTDIR)	

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT): FORCE
	@$(MAKE) -C $(LIBFTDIR)

clean:
	@rm -rf $(OBJ)
	@$(MAKE) clean -C $(LIBFTDIR)
	@$(MAKE) clean -C $(TESTDIR)

fclean: clean
	@rm -rf $(NAME) 
	@$(MAKE) fclean -C $(LIBFTDIR)
	@$(MAKE) fclean -C $(TESTDIR)

re: fclean all

ret: fclean test

FORCE:
