# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/16 17:12:49 by sboulain          #+#    #+#              #
#    Updated: 2024/02/02 14:23:35 by sboulain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= megaphone.cpp
OBJS			= $(SRCS:.cpp=.o)

CC				= c++
RM				= rm -f
CPPFLAGS		= -Wall -Wextra -Werror -I. -std=c++98 -fsanitize=address

NAME			= megaphone


all:			$(NAME)

%.o:			%.cpp
				$(CC) $(CPPFLAGS) -c -o $@ $<

$(NAME):		$(OBJS)
				c++ $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

test:			$(NAME)
				./megaphone "shhhhh... I think the students are asleep..."
				./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
				./megaphone

.PHONY:			all clean fclean re test