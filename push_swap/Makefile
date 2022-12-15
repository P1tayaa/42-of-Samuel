SRCS			= main.c
# SRCS_BONUS		= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
# ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS			= $(SRCS:%.c=%.o)
# OBJS_BONUS		= $(SRCS_BONUS:%.c=%.o)
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra

# ifdef WITH_BONUS
# REG_OBJS = $(OBJS) $(OBJS_BONUS)
# else
REG_OBJS = $(OBJS)
# endif

NAME			= push_swap.a
all:			$(NAME)
$(NAME):		$(REG_OBJS)
				@ar -crs $(NAME) $(REG_OBJS)
clean:
				# @rm -f $(OBJS_BONUS)
				@rm -f $(OBJS)
fclean:			clean
				@rm -f $(NAME)
re:             fclean $(NAME)

# bonus: 			
# 				@make WITH_BONUS=1 all

.PHONY:			all clean fclean re
