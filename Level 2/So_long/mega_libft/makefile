SRCS			= ft_strlen.c ft_isdigit.c ft_isupper.c ft_islower.c ft_isalpha.c ft_isalnum.c \
ft_isascii.c ft_isprint.c ft_itoa.c ft_memset.c ft_bzero.c ft_strcat.c ft_strcpy.c ft_strdup.c \
ft_putchar.c ft_putstr.c ft_putnbr.c ft_putendl.c ft_strnew.c ft_strjoin.c ft_memccpy.c \
ft_memcpy.c ft_atoi.c ft_tolower.c ft_toupper.c ft_calloc.c ft_memmove.c ft_strlcpy.c \
ft_strlcat.c ft_strchr.c ft_strrchr.c ft_memchr.c ft_strtrim.c ft_strncmp.c ft_memcmp.c \
ft_strnstr.c ft_substr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_strmapi.c ft_striteri.c ft_split.c \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
ft_printf.c ft_printf_utils.c \
ft_get_next_line.c ft_get_next_line_utils.c
OBJS			= $(SRCS:%.c=%.o)
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -I.

NAME			= libft.a
all:			$(NAME)
$(NAME):		$(OBJS)
				@ar -crs $(NAME) $(OBJS)
clean:
				@rm -f $(OBJS)
fclean:			clean
				@rm -f $(NAME)
re:             fclean $(NAME)

bonus:
				@make WITH_BONUS=1 all

.PHONY:			all clean fclean re
