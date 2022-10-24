SRCS			= ft_printf.c
OBJS			= $(SRCS:%.c=%.o)
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -I.
NAME			= libftprintf.a
all:			$(NAME)
$(NAME):		$(OBJS)
				ar -crs $(NAME) $(OBJS) libft.a
				@echo   :white_check_mark:Done!
clean:
				@rm -f $(OBJS)
fclean:			clean
				@rm -f $(NAME)
				@echo   Cleaned!
re:             fclean $(NAME)

.PHONY:			all clean fclean re
