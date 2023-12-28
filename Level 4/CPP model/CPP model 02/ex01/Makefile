SRCS			= main.cpp Fixed.cpp
OBJS			= $(SRCS:.cpp=.o)

CPP				= g++
RM				= rm -f
STDCPP			= -std=c++98
CPPFLAGS		= -Wall -Wextra -Werror -I. -fsanitize=address

NAME			= Fixed

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re test
