.PHONY: 	all clean fclean re FORCE

NAME 		= runtests 

CC 		= gcc
CFLAGS 		= -Wall -Wextra -Werror -g -O0 -fsanitize=address -fno-omit-frame-pointer
MAINDIR		= ..

include		$(MAINDIR)/sources.mk
vpath %.c $(LOGICDIRS)

LIBFTDIR 	= $(MAINDIR)/libft
LIBFTNAME 	= libft.a
LIBFT 		= $(LIBFTDIR)/$(LIBFTNAME)
LFLAGS		= -L$(LIBFTDIR) -l$(patsubst lib%, %, $(LIBFTNAME:.a=))

INCLUDES 	= -I$(MAINDIR)/includes -I$(LIBFTDIR)

CRITDIR 	:= $(shell brew --prefix criterion 2>/dev/null)
CRITINCL	= -I$(CRITDIR)/include 
CRITLIB		= -L$(CRITDIR)/lib -lcriterion 

MAINSRCS 	= $(LOGICSRCS)

MAINOBJS 	= $(MAINSRCS:.c=.o)

TESTSRCS	= $(wildcard *.c)
TESTOBJS	= $(TESTSRCS:.c=.o)

all: $(NAME)
	@./$(NAME)

$(NAME): 	$(MAINOBJS) $(TESTOBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(MAINOBJS) $(TESTOBJS) $(LFLAGS) $(CRITLIB) -fsanitize=address -o $(NAME)

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
