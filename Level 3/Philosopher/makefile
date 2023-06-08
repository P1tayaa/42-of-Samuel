
SRCS			= main.c untils.c

OBJS			= $(SRCS:%.c=%.o)

CC				= gcc

CFLAGS			= -Wall -Werror -Wextra -I. -fsanitize=address
# CFLAGS			= -Wall -Werror -Wextra -I.

NAME			= philosopher

.c.o:
				gcc -c $< -o $@

all:			$(NAME)

$(NAME): $(OBJS)
				$(CC) $(CFLAGS) -o philosopher $(OBJS)

clean:
				@rm -f $(OBJS)

fclean:			clean
				@rm -f $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
