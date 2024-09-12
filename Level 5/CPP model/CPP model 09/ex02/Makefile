SRCS			= main.cpp

SRCSPATH		= src/
BINPATH			= bin/

OBJS			= $(addprefix $(BINPATH), $(SRCS:.cpp=.o))

CC				= c++
CFLAGS			= -Wall -Wextra -Werror -I. -fsanitize=address -g

NAME			=	PmergeMe

all:			$(NAME)

$(NAME):		$(OBJS)	
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 	

$(BINPATH)%.o: $(SRCSPATH)%.cpp | $(BINPATH)
				$(CC) $(CFLAGS) -c $< -o $@

$(BINPATH):
				@mkdir -p $(BINPATH)

clean:
				@rm -f $(OBJS) $(OBJS_BONUS) test_demo
				@rm -rf $(BINPATH)

fclean:			clean
				@rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus
