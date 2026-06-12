.PHONY: 	all clean fclean re FORCE

NAME 		= runtests 

CC 		= gcc
CFLAGS 		= -Wall -Wextra -Werror -g -O0
MAINDIR		= ..
INCLUDES 	= -I$(MAINDIR)/includes

LIBFTDIR 	= $(MAINDIR)/libft
LIBFTNAME 	= libft.a
LIBFT 		= $(LIBFTDIR)/$(LIBFTNAME)
LFLAGS		= -L$(LIBFTDIR) -l$(patsubst lib%, %, $(LIBFTNAME:.a=))

CRITDIR 	:= $(shell brew --prefix criterion 2>/dev/null)
CRITINCL	= -I$(CRITDIR)/include 
CRITLIB		= -L$(CRITDIR)/lib -lcriterion 

MAINSRCS 	= helpers.c \
		  stack_algo.c \
		  stack_api_push.c \
		  stack_api_swap.c \
		  stack_init.c \
		  stack_api_rotate.c \
		  stack_api_revrotate.c
MAINOBJS 	= $(MAINSRCS:.c=.o)

TESTSRCS	= $(wildcard *.c)
TESTOBJS	= $(TESTSRCS:.c=.o)

all: $(NAME)
	@./$(NAME)

$(NAME): 	$(MAINOBJS) $(TESTOBJS) $(LIBFT)
		@$(CC) $(CFLAGS) $(MAINOBJS) $(TESTOBJS) $(LFLAGS) $(CRITLIB) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) $(CRITINCL) -c $< -o $@

%.o: $(MAINDIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT): FORCE
	@$(MAKE) -C $(LIBFTDIR)

clean:
	@rm -rf $(MAINOBJS) $(TESTOBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

FORCE:
