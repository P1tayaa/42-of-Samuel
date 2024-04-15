SRCS			= main.cpp AMateria.cpp ICharacter.cpp
OBJS			= $(SRCS:.cpp=.o)

CC				= c++
RM				= rm -f
STDCPP			= -std=c++98
CPPFLAGS		= -Wall -Wextra -Werror -I. -fsanitize=address

NAME			= Animals

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re test
