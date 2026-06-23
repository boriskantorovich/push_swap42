NAME 			= push_swap
CC 				= gcc
CFLAGS 			= -g -Wall -Wextra -Werror

PRINTFDIR 		= ./libft/ft_printf
PRINTFNAME 		= libftprintf.a
PRINTF			= $(PRINTFDIR)/$(PRINTFNAME)
PRINTFLFLAGS	= -L$(PRINTFDIR) -l$(patsubst lib%, %, $(PRINTFNAME:.a=))

INCLUDES 		= -Iinclude -I$(PRINTFDIR)

SRCS 			= $(wildcard operations/*.c strategies/*.c utils/*.c input/*.c *.c)

OBJS 			= $(SRCS:.c=.o)
	
all: $(NAME)

$(NAME): $(OBJS) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS) $ $(PRINTFLFLAGS) -o $(NAME) -lm

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(PRINTF): FORCE 
	@$(MAKE) -C $(PRINTFDIR)

clean:
	@rm -rf $(OBJS)
	@$(MAKE) clean -C $(PRINTFDIR)

fclean: clean 
	@rm -rf $(NAME) 
	@$(MAKE) fclean -C $(PRINTFDIR)

re: fclean all

debug: $(PRINTF)
	@gcc -g $(INCLUDES) operations/* strategies/* utils/* input/* *.c $(PRINTFLFLAGS) -o push_swap 

norm:
	@norminette $(SRCS) include/*.h | grep -v ": OK!" || echo "All OK!"

format:
	@c_formatter_42 $(shell find . -name '*.c') include/*.h


### shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt)
checker:
	rm -rf checker* && wget https://cdn.intra.42.fr/document/document/49766/checker_linux -O checker_linux && chmod +x checker_linux

FORCE:

.PHONY: 	all clean fclean re debug norm format FORCE
