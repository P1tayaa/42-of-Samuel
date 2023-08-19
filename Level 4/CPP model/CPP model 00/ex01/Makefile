# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/16 22:33:48 by sboulain          #+#    #+#              #
#    Updated: 2023/08/16 22:33:48 by sboulain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= phonebook.cpp
OBJS			= $(SRCS:.cpp=.o)

CPP				= g++
RM				= rm -f
# CPPFLAGS		= -Wall -Wextra -Werror -I.

NAME			= megaphone

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re test
