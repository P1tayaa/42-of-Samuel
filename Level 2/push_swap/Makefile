# Compiler
CC = 			gcc

# Flags
CFLAGS 			= -Wall -Werror -Wextra

PUSH_SWAP_SRCS = src/push_swap.c src/stack_making.c src/index_stack_a.c src/quicksort_for_index.c src/stack_change_tools.c \
				  src/stack_action_1.c src/stack_action_2.c src/stack_action_3.c \
				  src/radix_sort.c src/short_sort.c
# PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)
PUSH_SWAP_OBJS = push_swap.o stack_making.o index_stack_a.o quicksort_for_index.o stack_change_tools.o \
				  stack_action_1.o stack_action_2.o stack_action_3.o \
				  radix_sort.o short_sort.o

CHECKER_SRCS = src/Bonus/b_checker.c src/Bonus/b_checker_2.c src/Bonus/b_stack_action_1.c src/Bonus/b_stack_action_2.c src/Bonus/b_stack_action_3.c \
				  src/Bonus/b_quicksort_for_index.c src/Bonus/b_stack_making.c src/Bonus/b_index_stack.c src/Bonus/b_stack_change_tools.c
# CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)
CHECKER_OBJS = b_checker.o b_checker_2.o b_stack_action_1.o b_stack_action_2.o b_stack_action_3.o \
				  b_quicksort_for_index.o b_stack_making.o b_index_stack.o b_stack_change_tools.o

LIBFT			= ./mega_libft/libft.a

all: push_swap

push_swap: $(PUSH_SWAP_OBJS)
	make -C ./mega_libft
	$(CC) $(CFLAGS) -o push_swap $(PUSH_SWAP_OBJS) $(LIBFT)

$(PUSH_SWAP_OBJS): $(PUSH_SWAP_SRCS)
	$(CC) $(CFLAGS) -c $(PUSH_SWAP_SRCS)

checker: $(CHECKER_OBJS)
	make -C ./mega_libft
	$(CC) $(CFLAGS) -o checker $(CHECKER_OBJS) $(LIBFT)

$(CHECKER_OBJS): $(CHECKER_SRCS)
	$(CC) $(CFLAGS) -c $(CHECKER_SRCS)

clean:
				@rm -f $(PUSH_SWAP_OBJS) && rm -f $(CHECKER_OBJS) && make clean -C ./mega_libft

fclean:			clean
				@rm -f push_swap && rm -f checker && make fclean -C ./mega_libft

re:				fclean $(NAME)

.PHONY:			all clean fclean re
