
SRCS			= so_long.c map_valid_string.c map_making.c flud_fill_check.c

OBJS			= $(SRCS:%.c=%.o)

CC				= gcc

# CFLAGS			= -Wall -Werror -Wextra -I. -fsanitize=address
CFLAGS			= -Wall -Werror -Wextra -Wunreachable-code -Ofast

NAME			= so_long

all:			$(NAME)

$(NAME):
				make -C ./mega_libft
				make -C ./MLX42/build
				$(CC) $(CFLAGS) -o $(NAME) $(SRCS) ./mega_libft/libft.a ./MLX42/build/libmlx42.a -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw3
				@echo   :white_check_mark:Done!



clean:
				@rm -f $(OBJS)

fclean:			clean
				@rm -f $(NAME)



# right one just for faster load I will use above

# clean:
# 				@rm -f $(OBJS) && make clean -C ./mega_libft && make -C ./mega_libft clean
# fclean:			clean
# 				@rm -f $(NAME) && make fclean -C ./mega_libft

re:				fclean $(NAME)

.PHONY:			all clean fclean re
