# before release: remove includes, .mk files paste sources here
include sources.mk
vpath %.c $(LOGICDIRS)

.PHONY: 	all clean fclean re test ret norm format FORCE

NAME 		= push_swap

CC 		= gcc
CFLAGS 		= -Wall -Wextra -Werror

LIBFTDIR 	= ./libft
LIBFTNAME 	= libft.a
LIBFT		= $(LIBFTDIR)/$(LIBFTNAME)
LFLAGS		= -L$(LIBFTDIR) -l$(patsubst lib%, %, $(LIBFTNAME:.a=))

INCLUDES 	= -Iincludes -I$(LIBFTDIR)

TESTDIR	 	= ./tests

SRCS 		= $(LOGICSRCS)

OBJS 		= $(SRCS:.c=.o)

all: 		$(NAME)

$(NAME): 	$(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

test:
	@$(MAKE) -C $(TESTDIR)	

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT): FORCE
	@$(MAKE) -C $(LIBFTDIR)

clean:
	@rm -rf $(OBJS)
	@$(MAKE) clean -C $(LIBFTDIR)
	@$(MAKE) clean -C $(TESTDIR)

fclean: clean
	@rm -rf $(NAME) 
	@$(MAKE) fclean -C $(LIBFTDIR)
	@$(MAKE) fclean -C $(TESTDIR)

re: fclean all

ret: fclean test

norm:
	@norminette $(shell find . -name '*.c' $(FINDEXCL)) includes/*.h \
		| grep -v ": OK!" || echo "All OK!"

format:
	@c_formatter_42 $(shell find . -name '*.c' $(FINDEXCL)) includes/*.h

FORCE:
