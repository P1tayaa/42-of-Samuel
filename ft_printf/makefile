
SRCS			= printf.c

OBJS			= $(SRCS:%.c=%.o)

CC				= gcc

CFLAGS			= -Wall -Werror -Wextra -I.

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):
				make -C ./libft
				cp ./libft/libft.a ./libftprintf.a
				$(CC) $(CFLAGS) -c -o $(OBJS) $(SRCS)
				ar -rs $(NAME) $(OBJS)
				@echo   :white_check_mark:Done!
clean:
				@rm -f $(OBJS) && make clean -C ./libft

fclean:			clean
				@rm -f $(NAME) && make fclean -C ./libft

re:				fclean $(NAME)

.PHONY:			all clean fclean re
