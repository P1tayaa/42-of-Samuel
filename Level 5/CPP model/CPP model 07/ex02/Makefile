# Source files
SRCS			= main.cpp

# Directories
SRCSPATH		= src/
BINPATH			= bin/

# Object files
OBJS			= $(addprefix $(BINPATH), $(SRCS:.cpp=.o))

# Compiler and flags
CC				= c++
CFLAGS			= -Wall -Wextra -Werror -I. -fsanitize=address

# Names
NAME			=	Array

# Default target
all:			$(NAME)

# Create the library
$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 	

# Compile source files into object files
$(BINPATH)%.o: $(SRCSPATH)%.cpp | $(BINPATH)
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

.PHONY:			all clean fclean re bonus
