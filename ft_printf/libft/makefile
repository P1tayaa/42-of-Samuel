SRCS			= ft_putchar_int.c ft_putstr_int.c
OBJS			= $(SRCS:%.c=%.o)
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -I.

NAME			= libft.a
all:			$(NAME)
$(NAME):		
				$(CC) $(CFLAGS) -c $(SRCS)
				ar -crs $(NAME) $(OBJS)
				@echo   :white_check_mark:Done!
clean:
				@rm -f $(OBJS)
fclean:			clean
				@rm -f $(NAME)
				@echo   Cleaned!
re:             fclean $(NAME)

.PHONY:			all clean fclean re
