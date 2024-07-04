# Source files
SRCS			= get_next_line.c get_next_line_utils.c

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
NAME			= getNextLine.a
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
				./$(TEST_NAME) this is a test

.PHONY:			all clean fclean re bonus
