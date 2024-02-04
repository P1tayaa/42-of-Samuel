SRCS			= Zombie.cpp randomChump.cpp newZombie.cpp main.cpp
OBJS			= $(SRCS:.cpp=.o)

CPP				= c++
RM				= rm -f
CPPFLAGS		= -Wall -Wextra -Werror -I. -fsanitize=address

NAME			= Zombie

all:			$(NAME)

%.o:			%.cpp
				$(CPP) $(CPPFLAGS) -c -o $@ $<

$(NAME):		$(OBJS)
				$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re test
