
SRCS			= push_swap.c stack_making.c index_stack_a.c stack_change_tools.c

OBJS			= $(SRCS:%.c=%.o)

CC				= gcc

# CFLAGS			= -Wall -Werror -Wextra -I. -fsanitize=address
CFLAGS			= -Wall -Werror -Wextra -I.

NAME			= push_swap

all:			$(NAME)

$(NAME):
				make -C ./mega_libft
				$(CC) $(CFLAGS) -o push_swap $(SRCS) ./mega_libft/libft.a
				@echo   :white_check_mark:Done!
clean:
				@rm -f $(OBJS) && make clean -C ./mega_libft

fclean:			clean
				@rm -f $(NAME) && make fclean -C ./mega_libft

re:				fclean $(NAME)

.PHONY:			all clean fclean re
