
SRCS			= push_swap.c stack_making.c index_stack_a.c stack_change_tools.c \
				  stack_action_1.c stack_action_2.c stack_action_3.c \
				  radix_sort.c short_sort.c

OBJ_FOLDER      = bin
OBJS			= $(SRCS:%.c=$(OBJ_FOLDER)/%.o)

CC				= gcc

# CFLAGS			= -Wall -Werror -Wextra -I. -fsanitize=address
CFLAGS			= -Wall -Werror -Wextra -I.

NAME			= push_swap

$(OBJ_FOLDER)/%.o: %.c
				gcc -c $< -o $@

all:			$(NAME)

$(NAME): $(OBJS)
				make -C ./mega_libft
				$(CC) $(CFLAGS) -o push_swap $(OBJS) ./mega_libft/libft.a
				@echo   :white_check_mark:Done!
clean:
				@rm -f $(OBJS) && make clean -C ./mega_libft

fclean:			clean
				@rm -f $(NAME) && make fclean -C ./mega_libft

re:				fclean $(NAME)

.PHONY:			all clean fclean re
