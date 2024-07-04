# Source files
SRCS			= ft_strlen.c ft_isdigit.c ft_isupper.c ft_islower.c ft_isalpha.c ft_isalnum.c \
                  ft_isascii.c ft_isprint.c ft_itoa.c ft_memset.c ft_bzero.c ft_strcat.c ft_strcpy.c \
                  ft_strdup.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putendl.c ft_strnew.c ft_strjoin.c \
                  ft_memccpy.c ft_memcpy.c ft_atoi.c ft_tolower.c ft_toupper.c ft_calloc.c ft_memmove.c \
                  ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_memchr.c ft_strtrim.c ft_strncmp.c \
                  ft_memcmp.c ft_strnstr.c ft_substr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
                  ft_putnbr_fd.c ft_strmapi.c ft_striteri.c ft_split.c
SRCS_BONUS		= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
                  ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

# Directories
SRCSPATH		= src/
BINPATH			= bin/

# Object files
OBJS			= $(addprefix $(BINPATH), $(SRCS:.c=.o))
OBJS_BONUS		= $(addprefix $(BINPATH), $(SRCS_BONUS:.c=.o))

# Compiler and flags
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -I.

# Names
NAME			= libft.a
TEST_NAME		= test_demo

# Default target
all:			$(NAME)

# Create the library
$(NAME):		$(OBJS)
				@ar -crs $(NAME) $(OBJS)

# Compile source files into object files
$(BINPATH)%.o: $(SRCSPATH)%.c | $(BINPATH)
				$(CC) $(CFLAGS) -c $< -o $@

# Create bin directory if it doesn't exist
$(BINPATH):
				@mkdir -p $(BINPATH)

# Clean object files
clean:
				@rm -f $(OBJS) $(OBJS_BONUS) test_demo
				@rm -rf $(BINPATH)

# Clean object files and the library
fclean:			clean
				@rm -f $(NAME)

# Recompile everything
re:				fclean all

# Compile with bonus files
bonus:			$(OBJS) $(OBJS_BONUS)
				@ar -crs $(NAME) $(OBJS) $(OBJS_BONUS)

test:			all
				$(CC) $(CFLAGS) -o $(TEST_NAME) test/main.c $(NAME) 	
				./$(TEST_NAME)

.PHONY:			all clean fclean re bonus
