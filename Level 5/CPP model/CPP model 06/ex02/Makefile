SRCS			= main.cpp Base.cpp
OBJS			= $(SRCS:.cpp=.o)

CC				= c++
RM				= rm -f
STDCPP			= -std=c++98
CPPFLAGS		= -Wall -Wextra -Werror -I. -fsanitize=address

NAME			= Identifie

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re test
	