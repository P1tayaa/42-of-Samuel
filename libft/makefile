SRCS            = ft_strlen.c ft_isdigit.c ft_isupper.c ft_islower.c ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_itoa.c ft_memset.c ft_bzero.c ft_strcat.c ft_strcpy.c ft_strdup.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putendl.c ft_strnew.c ft_strjoin.c ft_memccpy.c ft_memcpy.c ft_atoi.c ft_tolower.c ft_roupper.c ft_calloc.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_memchr.c
OBJS            = $(SRCS:%.c=%.o)
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -I.

NAME            = libft.a
all:            $(NAME)
$(NAME):        $(OBJS)
				ar -crs $(NAME) $(OBJS)
				@echo   :white_check_mark:Done!
clean:
				@rm -f $(OBJS)
fclean:			clean
				@rm -f $(NAME)
				@echo   :soap:Cleaned!
re:             fclean $(NAME)

.PHONY:         all clean fclean re
