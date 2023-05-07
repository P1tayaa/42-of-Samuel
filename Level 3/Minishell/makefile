# Compiler
CC = 			gcc

# Flags
CFLAGS 			= -Wall -Werror -Wextra -I.

MINI_SHELL_SRCS = main.c

# PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)
MINI_SHELL_OBJS = main.o
				
LIBFT			= ./mega_libft/libft.a

all: minishel

minishell: $(MINI_SHELL_OBJS)
	make -C ./mega_libft
# $(CC) $(CFLAGS) -o push_swap $(PUSH_SWAP_OBJS) $(LIBFT)


$(MINI_SHELL_OBJS): $(MINI_SHELL_SRCS)
	$(CC) $(CFLAGS) -c $(MINI_SHELL_SRCS)


clean:
				@rm -f $(MINI_SHELL_OBJS) && make clean -C ./mega_libft

fclean:			clean
				@rm -f minishell && make fclean -C ./mega_libft

re:				fclean $(NAME)

.PHONY:			all clean fclean re
