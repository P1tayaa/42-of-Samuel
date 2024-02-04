# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/16 22:33:48 by sboulain          #+#    #+#              #
#    Updated: 2024/02/04 13:27:26 by sboulain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= phonebook.cpp
OBJS			= $(SRCS:.cpp=.o)

CPP				= c++
RM				= rm -f
CPPFLAGS		= -Wall -Wextra -Werror -I. -fsanitize=address

NAME			= phonebook

all:			$(NAME)

%.o:			%.cpp
				$(CC) $(CPPFLAGS) -c -o $@ $<

$(NAME):		$(OBJS)
				$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re test
