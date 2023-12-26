SRCS			= Zombie.cpp randomChump.cpp newZombie.cpp main.cpp
OBJS			= $(SRCS:.cpp=.o)

CPP				= g++
RM				= rm -f
# CPPFLAGS		= -Wall -Wextra -Werror -I.

NAME			= Zombie

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re test
