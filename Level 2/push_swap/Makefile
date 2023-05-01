# Compiler
CC = 			gcc

# Flags
CFLAGS 			= -Wall -Werror -Wextra -I.

PUSH_SWAP_SRCS = push_swap.c stack_making.c index_stack_a.c quicksort_for_index.c stack_change_tools.c \
				  stack_action_1.c stack_action_2.c stack_action_3.c \
				  radix_sort.c short_sort.c
# PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)
PUSH_SWAP_OBJS = push_swap.o stack_making.o index_stack_a.o quicksort_for_index.o stack_change_tools.o \
				  stack_action_1.o stack_action_2.o stack_action_3.o \
				  radix_sort.o short_sort.o

CHECKER_SRCS = Bonus/b_checker.c Bonus/b_checker_2.c Bonus/b_stack_action_1.c Bonus/b_stack_action_2.c Bonus/b_stack_action_3.c \
				  Bonus/b_quicksort_for_index.c Bonus/b_stack_making.c Bonus/b_index_stack.c Bonus/b_stack_change_tools.c
# CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)
CHECKER_OBJS = b_checker.o b_checker_2.o b_stack_action_1.o b_stack_action_2.o b_stack_action_3.o \
				  b_quicksort_for_index.o b_stack_making.o b_index_stack.o b_stack_change_tools.o
				
LIBFT			= ./mega_libft/libft.a

all: pushswap

pushswap: $(PUSH_SWAP_OBJS)
	make -C ./mega_libft
# $(CC) $(CFLAGS) -o push_swap $(PUSH_SWAP_OBJS) $(LIBFT)

checker: $(CHECKER_OBJS)
	make -C ./mega_libft
	$(CC) $(CFLAGS) -o checker $(CHECKER_OBJS) $(LIBFT)

$(PUSH_SWAP_OBJS): $(PUSH_SWAP_SRCS)
	$(CC) $(CFLAGS) -c $(PUSH_SWAP_SRCS)

$(CHECKER_OBJS): $(CHECKER_SRCS)
	$(CC) $(CFLAGS) -c $(CHECKER_SRCS)

clean:
				@rm -f $(PUSH_SWAP_OBJS) && rm -f $(CHECKER_OBJS) && make clean -C ./mega_libft

fclean:			clean
				@rm -f pushswap && rm -f checker && make fclean -C ./mega_libft

re:				fclean $(NAME)

.PHONY:			all clean fclean re
