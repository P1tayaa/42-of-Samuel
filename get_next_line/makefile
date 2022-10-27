
SRCS			= get_next_line.c

OBJS			= $(SRCS:%.c=%.o)

CC				= gcc

CFLAGS			= -Wall -Werror -Wextra -I.

NAME			= get_next_line.a

all:			$(NAME)

$(NAME):
				$(CC) $(CFLAGS) -c -o $(OBJS) $(SRCS)
				ar -rs $(NAME) $(OBJS)
				@echo   :white_check_mark:Done!
clean:
				@rm -f $(OBJS)

fclean:			clean
				@rm -f $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
