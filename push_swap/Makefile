<<<<<<< HEAD

SRCS			= push_swap.c

OBJS			= $(SRCS:%.c=%.o)

CC				= gcc

# CFLAGS			= -Wall -Werror -Wextra -I. -fsanitize=address
CFLAGS			= -Wall -Werror -Wextra -I.

NAME			= push_swap.a

all:			$(NAME)

$(NAME):
				make -C ./mega_libft
				$(CC) $(CFLAGS) -o push_swap $(SRCS) ./mega_libft/libft.a
				@echo   :white_check_mark:Done!
clean:
				@rm -f $(OBJS) && make clean -C ./mega_libft

fclean:			clean
				@rm -f $(NAME) && make fclean -C ./mega_libft

re:				fclean $(NAME)
=======
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
>>>>>>> df2daa1c8adea8f34c1d57aca47da3807dbe6684

.PHONY:			all clean fclean re
