
SRCS			= main.c untils.c philosopher.c make_philo.c

OBJS			= $(SRCS:%.c=%.o)

CC				= gcc

# CFLAGS			= -Wall -Werror -Wextra -pthread -g -fsanitize=address
CFLAGS = -Wall -Werror -Wextra -pthread -g -fsanitize=address
# CFLAGS			= -Wall -Werror -Wextra -I.

NAME			= philosopher

.c.o:
				gcc -c $< -o $@

all:			$(NAME)

$(NAME): $(OBJS)
				$(CC) $(CFLAGS) -o philo $(OBJS)

clean:
				@rm -f $(OBJS)

fclean:			clean
				@rm -f $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
