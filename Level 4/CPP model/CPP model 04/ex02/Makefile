SRCS			= main.cpp animals.cpp brain.cpp
OBJS			= $(SRCS:.cpp=.o)

CC				= c++
RM				= rm -f
STDCPP			= -std=c++98
CPPFLAGS		= -Wall -Wextra -Werror -I. -fsanitize=address

NAME			= Animals

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re test
