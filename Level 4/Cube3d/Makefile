
SRCS			= main.c

OBJS			= $(SRCS:%.c=%.o)

CC				= gcc

# CFLAGS			= -Wall -Werror -Wextra -fsanitize=address
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -lm libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
# CFLAGS			= -Wall -Werror -Wextra -I.

NAME			= cube3d

.c.o:
				gcc -c $< -o $@

all:			$(NAME)

$(NAME): $(OBJS)
				$(CC) $(CFLAGS) -o cube3d $(OBJS) libmlx42.a

clean:
				@rm -f $(OBJS)

fclean:			clean
				@rm -f $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
