SRCS			= ft_printf.c ft_printf_utils.c

OBJS			= $(SRCS:%.c=%.o)

CC				= gcc

CFLAGS			= -Wall -Werror -Wextra -I.

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):
				$(CC) $(CFLAGS) -c $(SRCS)
				ar -rs $(NAME) $(OBJS)
				@echo   :white_check_mark:Done!
clean:
				@rm -f $(OBJS)

fclean:			clean
				@rm -f $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
